/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 17:37:54 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/11 17:37:56 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
