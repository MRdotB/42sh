/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   router.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 16:39:58 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/04 19:28:14 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bcsh.h"

static int	builtin(t_cfg *cfg, char **entry)
{
	int			i;
	static void	(*f[])(t_cfg *cfg, char **entry) =
	{ bc_cd, bc_exit, bc_clear, bc_pwd, bc_env, bc_getenv, bc_setenv,
		bc_unsetenv };
	static char	*bultins[] =
	{ "cd", "exit", "clear", "pwd", "env", "getenv", "setenv",
		"unsetenv" };

	i = 0;
	while (i < 8)
	{
		if (ft_strcmp(bultins[i], entry[0]) == 0)
		{
			f[i](cfg, entry);
			return (1);
		}
		i++;
	}
	return (0);
}

int	path_binary(t_cfg *cfg, char **entry)
{
	pid_t	father;
	char	**env;
	char	*value;

	if ((value = ht_get(cfg->binary, entry[0])) == NULL)
	{
		bc_error_file("command not found: ", entry[0]);
		return (0);
	}
	if (access(value, F_OK) == -1)
		bc_error_file("command not found: ", value);
	else if (access(value, X_OK) == -1)
		bc_error_file("cannot execute ", value);
	else
	{
		father = fork();
		env = env_to_tab(cfg->env);
		if (father)
			wait(&father);
		else
			execve(value, av_parse(cfg, entry), env);
		free_double_tab(env);
	}
	return (1);
}

int	entry_binary(t_cfg *cfg, char **entry)
{
	pid_t			father;
	char			**env;
	struct stat		fs;

	lstat(entry[0], &fs);
	if ((ft_strncmp("./", entry[0], 2) != 0) && entry[0][0] != '/')
		return (0);
	if (access(entry[0], F_OK) == -1 || ft_strcmp("/", entry[0]) == 0)
		bc_error_file("exec: not found ", entry[0]);
	else if (S_ISDIR(fs.st_mode))
		bc_error_file("exec: cannot execute a directory ", entry[0]);
	else if (access(entry[0], X_OK) == -1)
		bc_error_file("exec: cannot execute ", entry[0]);
	else
	{
		father = fork();
		env = env_to_tab(cfg->env);
		if (father)
			wait(&father);
		else
			execve(entry[0], av_parse(cfg, entry), env);
		free_double_tab(env);
	}
	return (1);
}

void		router(t_cfg *cfg, char *line)
{
	char		**entry;

	entry = ft_strsplitstr(line, " \t");
	free(line);
	if (*entry == NULL)
	{
		free_double_tab(entry);
		return ;
	}
	if (!entry_binary(cfg, entry))
		if (!builtin(cfg, entry))
			path_binary(cfg, entry);
	free_double_tab(entry);
}
