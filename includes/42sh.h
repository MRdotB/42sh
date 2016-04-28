/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 15:58:58 by bchaleil          #+#    #+#             */
/*   Updated: 2016/04/28 19:22:45 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S42_SH_H
# define S42_SH_H

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

# define PROMPT "$> "

/*
typedef struct		s_bultin
{
	char[16]		name;
	void (*entry)			content_size;
	struct s_bultin	*next;
}					t_bultin;
*/

void	router(char *line);
void	bc_cd(char **path);
void	bc_exit(char **path);


#endif
