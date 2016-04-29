/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 12:42:18 by bchaleil          #+#    #+#             */
/*   Updated: 2016/04/29 12:42:44 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int		main(void)
{
	char	*line;

	while (write(1, PROMPT, 3) && (ft_gnl(0, &line) != 0))
		router(line);
}

/*
int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	char	**args;
	int		ret;
	pid_t	fat;

	fd = 0;
	ret = 1;
	if (ac != 1 && av[0])
		return (0);
	while (write(1, "$> ", 3) && (ret = ft_gnl(0, &line)) != 0)
	{
		if (!ft_strcmp("exit", line))
			exit (-1);
		fat = fork();
		if (fat)
			wait(&fat);
		else
		{
			if (line[0] == 'l' && line[1] == 's')
			{
				args = ft_strsplit(line, ' ');
				execve("/bin/ls", args, NULL);
			}
			else if (line[0] == 'c' && line[1] == 'd')
			{
				args = ft_strsplit(line, ' ');
				chdir(args[1]);
				printf("%s\n", args[1]);
			}
		}
	}
	close(fd);
	return (0);
}
*/
