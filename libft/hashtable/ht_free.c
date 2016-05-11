/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 17:38:00 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/11 17:38:01 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
