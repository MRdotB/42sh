/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 17:41:49 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/11 17:45:01 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bcsh.h"

static t_env	*env_cpy(t_env *origin)
{
	t_env	*cpy;
	char	**env;

	env = env_to_tab(origin);
	cpy = env_init(env);
	free_double_tab(env);
	return (cpy);
}

static int		bc_env_option_end(char **path, int i)
{
	if (ft_strcmp("-h", path[i]) == 0)
		return (help());
	else if (ft_strcmp("-u", path[i]) == 0)
	{
		if (path[++i] == NULL)
		{
			bc_error("env: option -u requires an argument");
			ft_putendl("Try 'env --h' for more information.");
			return (0);
		}
		else if (ft_strindexof(path[i], '=') != -1)
		{
			bc_error_file("env: Invalid argument cannot unset: ", path[i]);
			return (0);
		}
		return (1);
	}
	else if ((ft_strcmp("-i", path[i]) == 0) || (ft_strcmp("--", path[i]) == 0))
		return (1);
	else
	{
		bc_error_file("env: invalid option --", path[i] + 1);
		ft_putendl("Try 'env --h' for more information.");
		return (0);
	}
}

static void		bc_env_set(t_env **cpy, char **path, int *i)
{
	char	**split;

	while (path[*i] && (ft_strindexof(path[*i], '=') != -1))
	{
		split = ft_strsplit(path[*i], '=');
		set_env(cpy, split[0], split[1]);
		free_double_tab(split);
		(*i)++;
	}
}

static void		bc_env_exec(t_cfg *cfg, char **path, t_env **cpy, int i)
{
	t_cfg	cfg_cpy;

	if (path[i])
	{
		cfg_cpy.binary = cfg->binary;
		cfg_cpy.env = *cpy;
		if (!entry_binary(&cfg_cpy, path + i))
			path_binary(&cfg_cpy, path + i);
	}
	else
		display_env(*cpy);
	clean_env(*cpy);
}

void			bc_env(t_cfg *cfg, char **path)
{
	int		i;
	t_env	*cpy;

	if (path[1] == NULL)
		return (display_env(cfg->env));
	i = 1;
	cpy = env_cpy(cfg->env);
	while (path[i] && *path[i] == '-')
	{
		if (bc_env_option_end(path, i) == 0)
			return (clean_env(cpy));
		if (ft_strcmp("-i", path[i]) == 0)
		{
			clean_env(cpy);
			cpy = NULL;
		}
		else if (ft_strcmp("-u", path[i]) == 0)
			unset_env(&cpy, path[++i]);
		else if (ft_strcmp("--", path[i++]) == 0)
			break ;
		i++;
	}
	bc_env_set(&cpy, path, &i);
	bc_env_exec(cfg, path, &cpy, i);
}
