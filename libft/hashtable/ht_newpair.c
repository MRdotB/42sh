/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_newpair.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 17:38:14 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/11 17:38:16 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
