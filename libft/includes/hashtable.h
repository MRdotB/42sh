/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:59:30 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/04 12:52:18 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_H
# define HASHTABLE_H
# include <limits.h>

struct		s_entry
{
	char			*key;
	char			*value;
	struct s_entry	*next;
};

typedef struct s_entry	t_entry;

struct		s_hashtable
{
	int				size;
	struct s_entry	**table;
};
typedef struct s_hashtable	t_hashtable;

t_hashtable	*ht_create(int size);
void		ht_free(t_hashtable *hashtable);
int			ht_hash(t_hashtable *hashtable, char *key);
t_entry		*ht_newpair(char *key, char *value);
void		ht_set(t_hashtable *hashtable, char *key, char *value);
char		*ht_get(t_hashtable *hashtable, char *key);

#endif
