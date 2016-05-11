/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 15:21:16 by bchaleil          #+#    #+#             */
/*   Updated: 2016/01/10 16:00:31 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;

	if (!(*needle))
		return ((char*)haystack);
	while (*haystack)
	{
		i = 0;
		while (*(needle + i) == *(haystack + i))
		{
			i++;
			if (*(needle + i) == '\0')
				return ((char*)haystack);
		}
		haystack++;
	}
	return (NULL);
}
