/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 17:26:43 by bchaleil          #+#    #+#             */
/*   Updated: 2016/02/24 15:43:38 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*r;
	unsigned int	i;

	i = 0;
	if (!(f) || !(s))
		return (NULL);
	r = (char*)ft_memalloc(sizeof(char) * ft_strlen(s) + 1);
	if (!(r))
		return (NULL);
	while (s[i])
	{
		r[i] = f(s[i]);
		i++;
	}
	r[i] = '\0';
	return (r);
}
