/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   router.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 16:39:58 by bchaleil          #+#    #+#             */
/*   Updated: 2016/04/29 17:03:24 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void	router(char *line)
{
	int			i;
	char		**entry;
	static void	(*f[8])(char **entry) =
	{ bc_cd, bc_exit, bc_clear, bc_pwd, bc_env, bc_getenv, bc_setenv, bc_unsetenv };
	static char	*bultins[] =
	{ "cd", "exit", "clear", "pwd", "env", "getenv", "setenv", "unsetenv" };

	i = 0;
	entry = ft_strsplit(line, ' ');
	while (i < 8)
	{
		if (ft_strcmp(bultins[i], entry[0]) == 0)
			f[i](entry);
		i++;
	}
	i = 0;
	while (entry[i])
		free(entry[i++]);
	free(entry);
	ft_memdel((void**)&line);
}
