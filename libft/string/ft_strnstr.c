/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 16:00:15 by bchaleil          #+#    #+#             */
/*   Updated: 2016/01/07 15:41:00 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	if (!(*needle))
		return ((char *)haystack);
	if (!(*haystack) || n == 0)
		return (NULL);
	if (*haystack == *needle)
		if (ft_strnstr(haystack + 1, needle + 1, n - 1) - 1 == haystack)
			return ((char *)haystack);
	return (ft_strnstr(haystack + 1, needle, n - 1));
}
