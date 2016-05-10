/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultins2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 13:12:56 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/04 19:13:46 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bcsh.h"

void	bc_getenv(t_cfg *cfg, char **path)
{
	char	*get;

	if (path[1] == NULL)
		return (bc_error("getenv: Missing arg."));
	else if (path[2])
		return (bc_error("getenv: Too much args."));
	if (!(get = get_env(cfg->env, path[1])))
		return (bc_error("getenv: Variable not found in env."));
	ft_putendl(get);
}

void	bc_unsetenv(t_cfg *cfg, char **path)
{
	if (path[1] == NULL)
		return (bc_error("unsetenv: Missing arg."));
	else if (path[2])
		return (bc_error("unsetenv: Too much args."));
	if (!(unset_env(&(cfg->env), path[1])))
		bc_error("unsetenv: Variable not found in env.");
}

void	bc_setenv(t_cfg *cfg, char **path)
{
	if (path[1] == NULL || path[2] == NULL)
		return (bc_error("setenv: Missing arg. usage: setenv var value"));
	else if (path[3])
		return (bc_error("unsetenv: Too much args. usage: setenv var value"));
	set_env(&(cfg->env), path[1], path[2]);
}
