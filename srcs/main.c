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

t_hashtable		*g_hashtable;

static void	shellception(void)
{
	char	*lvl;
	char	*itoa;

	lvl = get_env("SHLVL");
	if (lvl)
	{
		itoa = ft_itoa(ft_atoi(lvl) + 1);
		set_env("SHLVL", itoa);
		free(itoa);
	}
	else
		set_env("SHLVL", "1");
}

int			main(int ac, char **av, char **env)
{
	char	*line;
	int		prompt_size;

	if (ac && *av)
		env_init(env);
	hash_binaries();
	shellception();
	prompt_size = ft_strlen(PROMPT);
	while (write(1, PROMPT, prompt_size) && (ft_gnl(0, &line) != 0))
		router(line);
	clean_env();
	ht_free(g_hashtable);
	return (0);
}
