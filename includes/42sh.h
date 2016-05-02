/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 15:58:58 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/02 13:45:47 by bchaleil         ###   ########.fr       */
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
//#include <linux/limits.h>

# define PROMPT "$> "

typedef struct		s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;


void	env_init(void);
char	**env_to_tab(void);
void	free_double_tab(char **tab);
void	clean_env(void);
void	display_env(void);
void	set_env(char *key, char *value, int overwrite);
int		get_env(char *key);
int		unset_env(char *key);

void	router(char *line);
void	bc_cd(char **path);
void	bc_exit(char **path);
void	bc_clear(char **path);
void	bc_pwd(char **path);
void	bc_env(char **path);
void	bc_getenv(char **path);
void	bc_setenv(char **path);
void	bc_unsetenv(char **path);

void	bc_error(char *error_msg);
char	**cpy_env(char **environ, int add, int del);
void	env_init(void);


#endif
