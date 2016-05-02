/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultins2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 13:12:56 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/02 13:57:05 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void	bc_env(char **path)
{
	if (path[1])
		return (bc_error("env: too much args."));
	display_env();
}

void	bc_getenv(char **path)
{
	if (path[1] == NULL)
		return (bc_error("getenv: missing arg."));
	else if (path[2])
		return (bc_error("getenv: too much args."));
	if (!(get_env(path[1])))
		bc_error("getenv: variable not found in env.");
}

void	bc_unsetenv(char **path)
{
	if (path[1] == NULL)
		return (bc_error("unsetenv: missing arg."));
	else if (path[2])
		return (bc_error("unsetenv: too much args."));
	if (!(unset_env(path[1])))
		bc_error("unsetenv: variable not found in env.");
}

void	bc_setenv(char **path)
{
	if (path[1] == NULL || path[2] == NULL || path[3] == NULL)
		return (bc_error("setenv: missing arg."));
	else if (path[4])
		return (bc_error("unsetenv: too much args."));
	set_env(path[1], path[2], ft_atoi(path[3]));
}
