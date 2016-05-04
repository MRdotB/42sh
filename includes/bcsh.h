/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bcsh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 15:58:58 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/04 17:10:40 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BCSH_H
# define BCSH_H

# include "libft.h"
# include "hashtable.h"

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <limits.h>
# include <dirent.h>
# include <sys/stat.h>

# ifdef __unix__
#  include <linux/limits.h>
# elif defined __APPLE__
#  include <sys/syslimits.h>
# endif

# define PROMPT "$> "

typedef struct		s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

void				env_init(char **env);
char				**env_to_tab(void);
void				free_double_tab(char **tab);
void				clean_env(void);
void				display_env(void);
void				set_env(char *key, char *value);
char				*get_env(char *key);
int					unset_env(char *key);

void				hash_binaries(void);

void				router(char *line);
void				bc_cd(char **path);
void				bc_exit(char **path);
void				bc_clear(char **path);
void				bc_pwd(char **path);
void				bc_env(char **path);
void				bc_getenv(char **path);
void				bc_setenv(char **path);
void				bc_unsetenv(char **path);

void				bc_error(char *error_msg);
void				bc_error_file(char *error_msg, char *file);

#endif
