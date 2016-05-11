/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_append.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:57:59 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/19 20:04:37 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_string_append(t_string *string, char *data)
{
	int	data_len;
	int	i;

	data_len = ft_strlen(data);
	while (string->alloced < string->length + data_len + 1)
		ft_string_enlarge(string);
	i = 0;
	while (data[i])
	{
		string->data[i + string->length] = data[i];
		i++;
	}
	string->length += data_len;
	return (1);
}
