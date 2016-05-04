/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 14:15:04 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/04 12:58:39 by bchaleil         ###   ########.fr       */
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
