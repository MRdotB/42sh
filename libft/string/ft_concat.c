/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 20:30:56 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/18 13:25:41 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_concat(char const *s1, char const *s2, int flag)
{
	char			*r;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	r = (char*)ft_memalloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!(r))
		return (NULL);
	while (s1[j])
		r[i++] = s1[j++];
	j = 0;
	while (s2[j])
		r[i++] = s2[j++];
	r[i] = '\0';
	if (flag & 1)
		ft_memdel((void**)&s1);
	if (flag & 2)
		ft_memdel((void**)&s2);
	return (r);
}
