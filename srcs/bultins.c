/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultins.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 17:13:17 by bchaleil          #+#    #+#             */
/*   Updated: 2016/04/28 19:22:59 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

//TODO cd env setenv unsetenv exit pwd

void	bc_cd(char **path)
{
	chdir(path[1]);
}
void	bc_exit(char **path)
{
	if (*path)
	{
		exit(0);
	}
}
