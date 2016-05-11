/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 16:56:35 by bchaleil          #+#    #+#             */
/*   Updated: 2016/01/10 16:01:53 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = ft_strlen(dest);
	if (n < i)
		return (n + ft_strlen(src));
	while (*src && i < n - 1)
	{
		dest[i] = *src;
		src++;
		++i;
	}
	dest[i] = '\0';
	return (ft_strlen(dest) + ft_strlen(src));
}
