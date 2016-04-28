/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   router.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 16:39:58 by bchaleil          #+#    #+#             */
/*   Updated: 2016/04/28 19:42:48 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void	router(char *line)
{
	int			i;
	char		**entry;
	static void	(*f[6])(char **entry) =
	{bc_exit };
	static char	*bultins[] =
	{"cd", "env", "setenv", "unsetenv", "exit", "pwd" };

	printf("DEBUG line: %s\n", line);
	entry = ft_strsplit(line, ' ');
	i = 0;
	while (i < 6)
	{
		if (ft_strcmp(bultins[i], entry[0]) == 0)
			f[i](entry);
		i++;
	}
}
