/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 17:38:05 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/11 17:38:06 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
