/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 17:38:10 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/11 17:38:11 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
