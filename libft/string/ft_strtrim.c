/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 15:58:15 by bchaleil          #+#    #+#             */
/*   Updated: 2016/02/24 17:10:29 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	c;

	if (s == NULL)
		return (NULL);
	if (*s == '\0')
		return (ft_strdup(""));
	while (ISSPACE(*s))
		s++;
	c = ft_strlen(s);
	if (c == 0)
		return (ft_strdup(""));
	while (ISSPACE(s[c - 1]))
		c--;
	return (ft_strsub(s, 0, c));
}
