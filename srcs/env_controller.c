/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_controller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 11:09:49 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/04 12:58:13 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bcsh.h"

static t_env	*new_elem(char *env)
{
	t_env	*r;
	char	*key;
	char	*value;
	int		equal_pos;

	equal_pos = ft_strindexof(env, '=');
	if (!(r = ft_memalloc(sizeof(*r))) || equal_pos == -1)
		return (NULL);
	if (!(key = ft_strnew(equal_pos)))
		return (NULL);
	value = ft_strdup(env + equal_pos);
	r->key = ft_strncpy(key, env, equal_pos - 1);
	r->value = value;
	r->next = NULL;
	return (r);
}

static t_env	*push_front(t_env *lst, t_env *el)
{
	if (lst == NULL)
		return (el);
	else
		el->next = lst;
	return (el);
}

char			**env_to_tab(t_env *head)
{
	t_env	*cpy;
	int		i;
	char	**r;
	char	*el;

	cpy = head;
	i = 0;
	while (cpy)
	{
		i++;
		cpy = cpy->next;
	}
	cpy = head;
	if (!(r = (char**)ft_memalloc(sizeof(char*) * (i + 1))))
		return (NULL);
	i = 0;
	while (cpy)
	{
		el = ft_strjoin(cpy->key, "=");
		el = ft_concat(el, cpy->value, 1);
		r[i++] = el;
		cpy = cpy->next;
	}
	return (r);
}

void			free_double_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

t_env			*env_init(char **env)
{
	int		i;
	t_env	*head;

	head = NULL;
	i = 0;
	while (env[i])
		i++;
	while (i > 0)
		head = push_front(head, new_elem(env[--i]));
	return (head);
}
