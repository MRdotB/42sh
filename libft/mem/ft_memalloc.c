/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 12:17:05 by bchaleil          #+#    #+#             */
/*   Updated: 2016/02/24 15:15:23 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *tmp;

	tmp = NULL;
	if (size)
	{
		if (!(tmp = malloc(size)))
			return (NULL);
		if (tmp)
			ft_bzero(tmp, size);
	}
	return (tmp);
}
