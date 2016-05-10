/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 12:42:18 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/04 18:34:57 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bcsh.h"

static void	shellception(t_cfg *cfg)
{
	char	*lvl;
	char	*itoa;

	lvl = get_env(cfg->env, "SHLVL");
	if (lvl)
	{
		itoa = ft_itoa(ft_atoi(lvl) + 1);
		set_env(&(cfg->env), "SHLVL", itoa);
		free(itoa);
	}
	else
		set_env(&(cfg->env), "SHLVL", "1");
}

int			main(int ac, char **av, char **env)
{
	char	*line;
	int		prompt_size;
	t_cfg	cfg;

	if (ac && *av)
		cfg.env = env_init(env);
	hash_binaries(&cfg);
	shellception(&cfg);
	prompt_size = ft_strlen(PROMPT);
	while (write(1, PROMPT, prompt_size) && (ft_gnl(0, &line) != 0))
		router(&cfg, line);
	clean_env(cfg.env);
	ht_free(cfg.binary);
	return (0);
}
