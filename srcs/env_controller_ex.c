/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_controller_ex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 11:22:19 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/04 12:58:29 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bcsh.h"

t_env	*g_head;

void	clean_env(void)
{
	t_env	*tmp;

	while (g_head)
	{
		free(g_head->key);
		free(g_head->value);
		tmp = g_head->next;
		free(g_head);
		g_head = tmp;
	}
}

void	display_env(void)
{
	t_env	*cpy;

	cpy = g_head;
	while (cpy)
	{
		ft_putstr(cpy->key);
		ft_putchar('=');
		ft_putendl(cpy->value);
		cpy = cpy->next;
	}
}

void	set_env(char *key, char *value)
{
	t_env	*cpy;

	cpy = g_head;
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
	cpy->next = g_head;
	g_head = cpy;
}

int		get_env(char *key)
{
	t_env	*cpy;

	cpy = g_head;
	while (cpy)
	{
		if (ft_strcmp(cpy->key, key) == 0)
		{
			ft_putendl(cpy->value);
			return (1);
		}
		cpy = cpy->next;
	}
	return (0);
}

int		unset_env(char *key)
{
	t_env	*cpy;
	t_env	*prev;

	cpy = g_head;
	prev = NULL;
	while (cpy)
	{
		if (ft_strcmp(cpy->key, key) == 0)
		{
			if (prev == NULL)
				g_head = g_head->next;
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
