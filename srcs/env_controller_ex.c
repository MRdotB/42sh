/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_controller_ex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 11:22:19 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/04 16:56:57 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bcsh.h"

t_env	*g_head;

void	clean_env(t_env *head)
{
	t_env	*tmp;

	while (head)
	{
		free(head->key);
		free(head->value);
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

void	display_env(t_env *head)
{
	t_env	*cpy;

	cpy = head;
	while (cpy)
	{
		ft_putstr(cpy->key);
		ft_putchar('=');
		ft_putendl(cpy->value);
		cpy = cpy->next;
	}
}

void	set_env(t_env **head, char *key, char *value)
{
	t_env	*cpy;

	if (value == NULL)
		return ;
	cpy = *head;
	while (cpy)
	{
		if (ft_strcmp(cpy->key, key) == 0)
		{
			free(cpy->value);
			cpy->value = ft_strdup(value);
			return ;
		}
		cpy = cpy->next;
	}
	if (!(cpy = ft_memalloc(sizeof(*cpy))))
		return ;
	cpy->key = ft_strdup(key);
	cpy->value = ft_strdup(value);
	cpy->next = *head;
	*head = cpy;
}

char	*get_env(t_env *head, char *key)
{
	t_env	*cpy;

	cpy = head;
	while (cpy)
	{
		if (ft_strcmp(cpy->key, key) == 0)
			return (cpy->value);
		cpy = cpy->next;
	}
	return (NULL);
}

int		unset_env(t_env **head, char *key)
{
	t_env	*cpy;
	t_env	*prev;

	cpy = *head;
	prev = NULL;
	while (cpy)
	{
		if (ft_strcmp(cpy->key, key) == 0)
		{
			if (prev == NULL)
				*head = (*head)->next;
			else
				prev->next = cpy->next;
			free(cpy->key);
			free(cpy->value);
			free(cpy);
			return (1);
		}
		prev = cpy;
		cpy = cpy->next;
	}
	return (0);
}
