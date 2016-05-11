/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 14:49:20 by bchaleil          #+#    #+#             */
/*   Updated: 2016/02/25 15:38:57 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t			count;
	char			*r;
	unsigned int	i;

	i = 0;
	count = ft_strlen(str);
	r = (char*)ft_memalloc(sizeof(*str) * count + 1);
	if (r == NULL)
		return (NULL);
	while (str[i])
	{
		r[i] = str[i];
		i++;
	}
	r[i] = '\0';
	return (r);
}
