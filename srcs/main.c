/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 12:42:18 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/04 12:59:03 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bcsh.h"

int		main(int ac, char **av, char **env)
{
	char	*line;
	int		prompt_size;

	if (ac && *av)
		env_init(env);
	hash_binaries();
	prompt_size = ft_strlen(PROMPT);
	while (write(1, PROMPT, prompt_size) && (ft_gnl(0, &line) != 0))
		router(line);
	return (0);
}
