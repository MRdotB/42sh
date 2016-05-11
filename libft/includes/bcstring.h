/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bcstring.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 17:39:39 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/11 17:39:41 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BCSTRING_H
# define BCSTRING_H

typedef struct		s_string
{
	char			*data;
	unsigned int	length;
	unsigned int	alloced;

}					t_string;

t_string			*ft_string_new(unsigned int length);
void				ft_string_free(t_string *string);
int					ft_string_enlarge(t_string *string);
int					ft_string_append(t_string *string, char *data);

#endif
