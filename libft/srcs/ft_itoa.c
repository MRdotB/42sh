/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 16:59:35 by bchaleil          #+#    #+#             */
/*   Updated: 2016/02/25 15:59:44 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_itoa_recurse(int n, int size, char *nbr)
{
	if (n < 0)
	{
		nbr[0] = '-';
		return (ft_itoa_recurse(n * -1, size, nbr));
	}
	if (n >= 10 && size >= 0)
	{
		nbr[size] = (n % 10) + '0';
		return (ft_itoa_recurse(n / 10, size - 1, nbr));
	}
	nbr[size] = n + '0';
	return (nbr);
}

static int		ft_numlen(int n)
{
	if (n < 0)
		return (ft_numlen(n * -1) + 1);
	if (n >= 10)
		return (ft_numlen(n / 10) + 1);
	return (1);
}

char			*ft_itoa(int n)
{
	char	*nbr;
	int		size;

	if (n <= -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_numlen(n);
	nbr = ft_strnew(size);
	if (nbr == NULL)
		return (NULL);
	return (ft_itoa_recurse(n, size - 1, nbr));
}
