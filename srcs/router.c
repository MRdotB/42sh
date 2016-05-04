/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   router.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 16:39:58 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/04 14:43:15 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bcsh.h"

t_hashtable	*g_hashtable;

static int	builtin(char **entry)
{
	int			i;
	static void	(*f[9])(char **entry) =
	{ bc_cd, bc_exit, bc_clear, bc_pwd, bc_env, bc_getenv, bc_setenv,
		bc_unsetenv, bc_unsetenv };
	static char	*bultins[] =
	{ "cd", "exit", "clear", "pwd", "env", "getenv", "setenv",
		"unsetenv", "unset" };

	i = 0;
	while (i < 9)
	{
		if (ft_strcmp(bultins[i], entry[0]) == 0)
		{
			f[i](entry);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	path_binary(char **entry)
{
	pid_t	father;
	char	**env;
	char	*value;

	if ((value = ht_get(g_hashtable, entry[0])) == NULL)
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
		env = env_to_tab();
		if (father)
			wait(&father);
		else
			execve(value, entry, env);
		free_double_tab(env);
	}
	return (1);
}

static	int	entry_binary(char **entry)
{
	pid_t	father;
	char	**env;

	if (ft_strncmp("./", entry[0], 2) != 0)
		return (0);
	if (access(entry[0], F_OK) == -1)
		bc_error_file("./: not found ", entry[0]);
	else if (access(entry[0], X_OK) == -1)
		bc_error_file("./: cannot execute ", entry[0]);
	else
	{
		father = fork();
		env = env_to_tab();
		if (father)
			wait(&father);
		else
			execve(entry[0], entry, env);
		free_double_tab(env);
	}
	return (1);
}

void		router(char *line)
{
	char		**entry;

	if (*line == '\0')
		return ;
	entry = ft_strsplit(line, ' ');
	if (!entry_binary(entry))
		if (!builtin(entry))
			path_binary(entry);
	free_double_tab(entry);
	free(line);
}
