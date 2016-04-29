/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 15:58:58 by bchaleil          #+#    #+#             */
/*   Updated: 2016/04/29 14:18:53 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S42_SH_H
# define S42_SH_H

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/syslimits.h>

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
void	bc_clear(char **path);
void	bc_pwd(char **path);
void	bc_env(char **path);
void	bc_getenv(char **path);

void	bc_error(char *error_msg);


#endif
