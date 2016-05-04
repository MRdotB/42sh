/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:58:10 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/04 12:58:51 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bcsh.h"

t_hashtable	*ht_create(int size)
{
	t_hashtable	*hashtable;
	int			i;

	if (size < 1)
		return (NULL);
	if ((hashtable = malloc(sizeof(t_hashtable))) == NULL)
		return (NULL);
	if ((hashtable->table = malloc(sizeof(t_entry*) * size)) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
		hashtable->table[i++] = NULL;
	hashtable->size = size;
	return (hashtable);
}

void		ht_free(t_hashtable *hashtable)
{
	int		i;
	t_entry	*tmp;
	t_entry	*next;

	i = -1;
	while (++i < hashtable->size)
	{
		if (hashtable->table[i] != NULL)
		{
			tmp = hashtable->table[i];
			while (tmp)
			{
				free(tmp->key);
				free(tmp->value);
				next = tmp->next;
				free(tmp);
				tmp = next;
			}
		}
	}
	free(hashtable->table);
	free(hashtable);
}

int			ht_hash(t_hashtable *hashtable, char *key)
{
	size_t	i;
	size_t	hashval;
	size_t	len;

	i = 0;
	hashval = 0;
	len = ft_strlen(key);
	while (i < len)
	{
		hashval += key[i];
		hashval += (hashval << 10);
		hashval ^= (hashval >> 6);
		++i;
	}
	hashval += (hashval << 3);
	hashval ^= (hashval >> 11);
	hashval += (hashval << 15);
	return (hashval % hashtable->size);
}
