/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultins1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 13:10:46 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/02 14:05:11 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

t_env	*g_head;

void	bc_cd(char **path)
{
	chdir(path[1]);
}

void	bc_exit(char **path)
{
	if (*path)
	{
		clean_env();
		exit(0);
	}
}

void	bc_clear(char **path)
{
	const char	*clear_screen_ansi;

	clear_screen_ansi = "\e[1;1H\e[2J";
	if (path[1])
		return (bc_error("clear: too much args."));
	ft_putstr_fd(clear_screen_ansi, STDOUT_FILENO);
}

void	bc_pwd(char **path)
{
	char current[PATH_MAX];

	if (path[1])
		return (bc_error("pwd: too much args."));
	ft_putendl(getcwd(current, PATH_MAX));
}
