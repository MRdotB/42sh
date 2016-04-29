/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   router.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 16:39:58 by bchaleil          #+#    #+#             */
/*   Updated: 2016/04/29 13:01:19 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void	router(char *line)
{
	int			i;
	char		**entry;
	static void	(*f[7])(char **entry) =
	{ bc_cd, bc_exit, bc_clear };
	static char	*bultins[] =
	{"cd", "exit", "clear", "env", "setenv", "unsetenv", "exit", "pwd" };

	printf("DEBUG line: %s\n", line);
	entry = ft_strsplit(line, ' ');
	i = 0;
	while (i < 7)
	{
		if (ft_strcmp(bultins[i], entry[0]) == 0)
			f[i](entry);
		i++;
	}
}
