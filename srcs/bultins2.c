/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultins2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 13:12:56 by bchaleil          #+#    #+#             */
/*   Updated: 2016/04/29 14:23:01 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

extern char	**environ;

void	bc_env(char **path)
{
	int	i;

	i = 0;
	if (*path)
		while (environ[i])
			ft_putendl(environ[i++]);
}

void	bc_getenv(char **path)
{
	int i;
	int equal_pos;

	i = 0;
	if (path[1] == NULL)
		return (bc_error("getenv: missing arg."));
	else if (path[2])
		return (bc_error("getenv: too much args."));
	while (environ[i])
	{
		equal_pos = ft_strindexof(environ[i], '=');
		if (ft_strncmp(path[1], environ[i], equal_pos - 1) == 0)
			return (ft_putendl(environ[i] + equal_pos));
		i++;
	}
	return (bc_error("getenv: variable not found in env."));
}
