/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strindexof.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 20:48:59 by bchaleil          #+#    #+#             */
/*   Updated: 2016/02/29 21:02:17 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strindexof(char *str, char c)
{
	int	i;

	if (str == NULL)
		return (-1);
	i = 0;
	while (str[i])
		if (str[i++] == c)
			return (i);
	return (-1);
}
