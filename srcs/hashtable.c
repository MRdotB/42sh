/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:58:10 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/02 19:14:18 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"
#include "libft.h"

hashtable_t	*ht_create(int size)
{
	hashtable_t	*hashtable;
	int			i;

	if (size < 1)
		return (NULL);
	if ((hashtable = malloc(sizeof(hashtable_t))) == NULL)
		return (NULL);
	if ((hashtable->table = malloc(sizeof(entry_t*) * size)) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
		hashtable->table[i++] = NULL;
	hashtable->size = size;
	return (hashtable);
}

void	ht_free(hashtable_t *hashtable)
{
	int		i;
	entry_t	*tmp;
	entry_t	*next;

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

int		ht_hash(hashtable_t *hashtable, char *key)
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


