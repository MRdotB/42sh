/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 17:52:24 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/19 19:07:12 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_string	*ft_string_new(unsigned int length)
{
	t_string	*new_string;

	if (length == 0)
		length = 16;
	new_string = (t_string*)ft_memalloc(sizeof(t_string));
	if (new_string == NULL)
		return (NULL);
	new_string->data = (char*)ft_memalloc(length * sizeof(char));
	if (new_string->data == NULL)
	{
		free(new_string);
		return (NULL);
	}
	new_string->length = 0;
	new_string->alloced = length;
	return (new_string);
}
