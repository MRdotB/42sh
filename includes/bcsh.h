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

typedef struct		s_cfg
{
	t_env			*env;	
	t_hashtable		*binary;
}					t_cfg;

t_env				*env_init(char **env);
char				**env_to_tab(t_env *env);
void				free_double_tab(char **tab);
void				clean_env(t_env *head);
void				display_env(t_env *head);
void				set_env(t_env **head, char *key, char *value);
char				*get_env(t_env *head, char *key);
int					unset_env(t_env **head, char *key);

void				hash_binaries(t_cfg *cfg);

void				router(t_cfg *cfg, char *line);
void				bc_cd(t_cfg *cfg, char **path);
void				bc_exit(t_cfg *cfg, char **path);
void				bc_clear(t_cfg *cfg, char **path);
void				bc_pwd(t_cfg *cfg, char **path);
void				bc_env(t_cfg *cfg, char **path);
void				bc_getenv(t_cfg *cfg, char **path);
void				bc_setenv(t_cfg *cfg, char **path);
void				bc_unsetenv(t_cfg *cfg, char **path);

void				bc_error(char *error_msg);
void				bc_error_file(char *error_msg, char *file);

char				**av_parse(t_cfg *cfg, char	**av);

#endif
