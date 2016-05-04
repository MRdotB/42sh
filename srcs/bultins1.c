/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultins1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 13:10:46 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/04 12:58:06 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bcsh.h"

t_env			*g_head;
t_hashtable		*g_hashtable;

void	bc_cd(char **path)
{
	if ((!path[1] || !ft_strcmp(path[1], "~")) && getenv("HOME"))
		chdir(getenv("HOME"));
	else if (path[2])
		return (bc_error("cd: too much args."));
	else if (chdir(path[1]) != -1)
		return ;
	else
	{
		if (access(path[0], F_OK) == -1)
			bc_error("cd: File does not exist.");
		else if (access(path[0], R_OK) == -1)
			bc_error("cd: Permission denied.");
	}
}

void	bc_exit(char **path)
{
	if (*path)
	{
		clean_env();
		ht_free(g_hashtable);
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
