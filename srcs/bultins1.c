/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultins1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 13:10:46 by bchaleil          #+#    #+#             */
/*   Updated: 2016/04/29 14:25:22 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void	bc_cd(char **path)
{
	chdir(path[1]);
}
void	bc_exit(char **path)
{
	if (*path)
		exit(0);
}

void	bc_clear(char **path)
{
	const char*	clear_screen_ansi;

	clear_screen_ansi = "\e[1;1H\e[2J";
	if (*path)
		ft_putstr_fd(clear_screen_ansi, STDOUT_FILENO);
}

void	bc_pwd(char **path)
{
	char current[PATH_MAX];

	if (*path)
		ft_putendl(getcwd(current, PATH_MAX));
}
