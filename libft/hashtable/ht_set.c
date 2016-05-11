/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 17:38:19 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/11 17:38:21 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
