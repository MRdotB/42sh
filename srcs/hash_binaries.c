/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_binaries.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 11:45:13 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/04 14:38:47 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bcsh.h"

void	hash_binaries(t_cfg *cfg)
{
	char			*value;
	char			**paths;
	int				i;
	struct dirent	*d;
	DIR				*dir;

	cfg->binary = ht_create(2048);
	i = -1;
	if (get_env(cfg->env, "PATH") == NULL)
		return ;
	paths = ft_strsplit(get_env(cfg->env, "PATH"), ':');
	while (paths[++i])
	{
		if ((dir = opendir(paths[i])) != 0)
			while ((d = readdir(dir)) != NULL)
			{
				value = ft_strjoin(paths[i], "/");
				value = ft_concat(value, d->d_name, 1);
				if (access(value, F_OK) == 0 || access(value, X_OK) == 0)
					ht_set(cfg->binary, d->d_name, value);
				free(value);
			}
		closedir(dir);
	}
	free_double_tab(paths);
}
