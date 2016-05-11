/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_enlarge.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:11:11 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/19 18:53:20 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_string_enlarge(t_string *string)
{
	char			*data;
	unsigned int	newsize;

	newsize = string->alloced * 2;
	data = (char*)ft_memalloc(newsize * sizeof(char));
	if (data == NULL)
		return (0);
	data = ft_strcpy(data, string->data);
	free(string->data);
	string->data = data;
	string->alloced = newsize;
	return (1);
}
