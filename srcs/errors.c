/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 14:15:04 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/11 17:46:17 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bcsh.h"

void	bc_error(char *error_msg)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(error_msg, 2);
	ft_putstr_fd(RESET, 2);
	ft_putchar('\n');
}

void	bc_error_file(char *error_msg, char *file)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(error_msg, 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(RESET, 2);
	ft_putchar('\n');
}

int		help(void)
{
	ft_putstr("Usage: env [OPTION]... [-] [NAME=VALUE]...");
	ft_putendl("[COMMAND [ARG]...];");
	ft_putendl("Set each NAME to VALUE in the environment and run COMMAND.");
	ft_putendl("  -i  start with an empty environment");
	ft_putendl("  -u  remove variable from the environment");
	ft_putendl("  -h  display this help and exit");
	ft_putendl("If no COMMAND, print the resulting environment.");
	return (0);
}
