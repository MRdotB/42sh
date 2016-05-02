/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_controller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 11:09:49 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/02 14:04:32 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

t_env		*g_head;
extern char	**environ;

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

char			**env_to_tab(void)
{
	t_env	*cpy;
	int		i;
	char	**r;
	char	*el;

	cpy = g_head;
	i = 0;
	while (cpy)
	{
		i++;
		cpy = cpy->next;
	}
	cpy = g_head;
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

void			env_init(void)
{
	int		i;

	g_head = NULL;
	i = 0;
	while (environ[i])
		i++;
	while (i > 0)
		g_head = push_front(g_head, new_elem(environ[--i]));
}
