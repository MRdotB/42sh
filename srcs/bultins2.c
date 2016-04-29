/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultins2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 13:12:56 by bchaleil          #+#    #+#             */
/*   Updated: 2016/04/29 18:30:32 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

char	**env_cpy;

char	**cpy_env(char **environ, int add, int del)
{
	char	**env_cpy;
	int		i;

	i = 0;
	while(environ[i])
		i++;
	if (!(env_cpy = (char**)ft_memalloc(sizeof(char*) * i + add + 1)))
		return (NULL);
	i = 0;
	while(environ[i])
	{
		env_cpy[i + add] = ft_strdup(environ[i]);
		if (del)
			free(environ[i]);
		i++;
	}
	env_cpy[i] = NULL;
	if (del)
		free(environ);
	return (env_cpy);
}

void	bc_env(char **path)
{
	int	i;

	i = 0;
	if (*path)
		while (env_cpy[i])
		{
			if (ft_strcmp(env_cpy[i], "_skip_") != 0)
				ft_putendl(env_cpy[i]);
			i++;
		}
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
	while (env_cpy[i])
	{
		equal_pos = ft_strindexof(env_cpy[i], '=');
		if (ft_strncmp(path[1], env_cpy[i], equal_pos - 1) == 0)
			return (ft_putendl(env_cpy[i] + equal_pos));
		i++;
	}
	return (bc_error("getenv: variable not found in env."));
}

void	bc_unsetenv(char **path)
{
	int	i;
	int	equal_pos;

	i = 0;
	while (env_cpy[i])
	{
		equal_pos = ft_strindexof(env_cpy[i], '=');
		if (ft_strncmp(path[1], env_cpy[i], equal_pos - 1) == 0)
		{
			free(env_cpy[i]);
			env_cpy[i] = ft_strdup("_skip_");
			return ;
		}
		i++;
	}
	bc_error("unsetenv: variable not found in env.");
}

void	bc_setenv(char **path)
{
	char	*var;
	int		i;
	int		equal_pos;

	i = 0;
	var = ft_concat(path[1], "=", 0);
	var = ft_concat(var, path[2], 1);
	while (env_cpy[i])
	{
		equal_pos = ft_strindexof(env_cpy[i], '=');
		if (ft_strncmp(path[1], env_cpy[i], equal_pos - 1) == 0)
		{
			if (path[3][0] == '1')
			{
				free(env_cpy[i]);
				env_cpy[i] = var;
				return ;
			}
			else if (path[3][0] == '0')
				return ;
		}
		i++;
	}
	env_cpy = cpy_env(env_cpy, 1, 1);
	env_cpy[0] = var;
}
