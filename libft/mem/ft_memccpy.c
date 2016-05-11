/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 12:01:45 by bchaleil          #+#    #+#             */
/*   Updated: 2016/01/07 15:43:36 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*src1;
	char	*dest1;

	src1 = (char *)src;
	dest1 = (char *)dest;
	i = 0;
	while (i < n)
	{
		dest1[i] = src1[i];
		if ((unsigned char)src1[i] == (unsigned char)c)
			return ((char *)dest + i + 1);
		i++;
	}
	return (NULL);
}
