/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:59:30 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/02 18:58:00 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

struct entry_s {
	char *key;
	char *value;
	struct entry_s *next;
};

typedef struct entry_s entry_t;

struct hashtable_s {
	int size;
	struct entry_s **table;	
};

typedef struct hashtable_s hashtable_t;

hashtable_t *ht_create(int size);
void		ht_free(hashtable_t *hashtable);
int 		ht_hash(hashtable_t *hashtable, char *key);
entry_t 	*ht_newpair( char *key, char *value );
void 		ht_set(hashtable_t *hashtable, char *key, char *value);
char 		*ht_get(hashtable_t *hashtable, char *key);
