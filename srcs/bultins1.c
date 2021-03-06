/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultins1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 13:10:46 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/11 18:22:42 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bcsh.h"

static void	bc_cd_ex(t_cfg *cfg, char *go_to)
{
	char	current[PATH_MAX];

	if (go_to == NULL)
		return (bc_error("cd: File does not exist."));
	else if (access(go_to, F_OK) == -1)
		bc_error("cd: File does not exist.");
	else if (access(go_to, R_OK) == -1)
		bc_error("cd: Permission denied.");
	else if (chdir(go_to) == 0)
	{
		set_env(&(cfg->env), "OLDPWD", get_env(cfg->env, "PWD"));
		set_env(&(cfg->env), "PWD", getcwd(current, PATH_MAX));
	}
	free(go_to);
}

void		bc_cd(t_cfg *cfg, char **path)
{
	char	*home;
	char	*prev;
	char	*go_to;

	go_to = NULL;
	if (!(home = get_env(cfg->env, "HOME")))
		home = "~";
	if (!(prev = get_env(cfg->env, "OLDPWD")))
		prev = "-";
	if (path[1] && path[2])
		bc_error("cd: Too much args. usage: cd dirname");
	else if (!path[1] || (path[1][0] == '~' && path[1][1] == '\0'))
		go_to = ft_strdup(home);
	else if (path[1][0] == '-' && path[1][1] == '\0')
		go_to = ft_strdup(prev);
	else if (ft_strncmp("~/", path[1], 2) == 0)
		go_to = ft_concat(home, path[1] + 1, 0);
	else
		go_to = ft_strdup(path[1]);
	bc_cd_ex(cfg, go_to);
}

void		bc_exit(t_cfg *cfg, char **path)
{
	int	e;

	e = 0;
	if (!path[1])
		e = 0;
	else if (path[2])
		return (bc_error("exit: Too much args. usage: exit value"));
	else
	{
		if (path[1])
			e = ft_atoi(path[1]);
		if (e <= 0)
			e = 0;
		if (e >= 255)
			e = 255;
	}
	free_double_tab(path);
	free_double_tab(cfg->cmd);
	clean_env(cfg->env);
	ht_free(cfg->binary);
	exit(e);
}

void		bc_clear(t_cfg *cfg, char **path)
{
	const char	*clear_screen_ansi;

	clear_screen_ansi = "\e[1;1H\e[2J";
	if (path[1] && cfg->env)
		return (bc_error("clear: Too much args. usage: clear"));
	ft_putstr_fd(clear_screen_ansi, STDOUT_FILENO);
}

void		bc_pwd(t_cfg *cfg, char **path)
{
	char	current[PATH_MAX];

	if (path[1] && cfg->env)
		return (bc_error("pwd: Too much args."));
	ft_putendl(getcwd(current, PATH_MAX));
}
