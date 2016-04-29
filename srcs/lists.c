/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 18:34:35 by bchaleil          #+#    #+#             */
/*   Updated: 2016/04/29 19:05:40 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

static t_binary	*new_elem(char *name, char *path)
{
	t_binary	*f;

	if (!(f = ft_memalloc(sizeof(t_binary))))
		return (NULL);
	f->name = name;
	f->path = path;
	f->next = NULL;
	return (f);
}

static t_binary	*push_front(t_binary *lst, t_binary *el)
{
	if (lst == NULL)
		return (el);
	else
		el->next = lst;
	return (el);
}

t_binary	*get_binary(char *paths)
{
	char	**p;
	int		i;
	t_binary *r;

		//dprintf(2, "SA MARCHE PAS");
	r = NULL;
	r = push_front(r, new_elem("test", "bin/"));
	ft_putendl(r->path);
	i = 0;
	p = ft_strsplit(paths, ':');
	while (p[i])
	{

		ft_putendl(p[i++]);
	}
	return (r);
}
