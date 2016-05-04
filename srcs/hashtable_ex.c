/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_ex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 11:46:09 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/04 12:58:57 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bcsh.h"

t_entry		*ht_newpair(char *key, char *value)
{
	t_entry *newpair;

	if ((newpair = malloc(sizeof(t_entry))) == NULL)
		return (NULL);
	if ((newpair->key = ft_strdup(key)) == NULL)
		return (NULL);
	if ((newpair->value = ft_strdup(value)) == NULL)
		return (NULL);
	newpair->next = NULL;
	return (newpair);
}

static void	ht_set_ex(t_entry *newpair, t_entry *next, t_entry *last)
{
	if (next == NULL)
		last->next = newpair;
	else
	{
		newpair->next = next;
		last->next = newpair;
	}
}

void		ht_set(t_hashtable *hashtable, char *key, char *value)
{
	int		bin;
	t_entry	*newpair;
	t_entry	*next;
	t_entry	*last;

	bin = ht_hash(hashtable, key);
	next = hashtable->table[bin];
	while (next != NULL && next->key != NULL && ft_strcmp(key, next->key) > 0)
	{
		last = next;
		next = next->next;
	}
	if (next != NULL && next->key != NULL && ft_strcmp(key, next->key) == 0)
	{
		free(next->value);
		next->value = ft_strdup(value);
		return ;
	}
	if ((newpair = ht_newpair(key, value)) && next == hashtable->table[bin])
	{
		newpair->next = next;
		hashtable->table[bin] = newpair;
	}
	else
		ht_set_ex(newpair, next, last);
}

char		*ht_get(t_hashtable *hashtable, char *key)
{
	int		bin;
	t_entry	*pair;

	bin = ht_hash(hashtable, key);
	pair = hashtable->table[bin];
	while (pair != NULL && pair->key != NULL && ft_strcmp(key, pair->key) > 0)
		pair = pair->next;
	if (pair == NULL || pair->key == NULL || ft_strcmp(key, pair->key) != 0)
		return (NULL);
	else
		return (pair->value);
}
