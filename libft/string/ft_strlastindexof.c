/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlastindexof.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 18:05:55 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/15 18:11:40 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlastindexof(char *str, char c)
{
	int	i;

	if (str == NULL)
		return (-1);
	i = ft_strlen(str);
	while (i > 0)
		if (str[i--] == c)
			return (i);
	return (-1);
}
