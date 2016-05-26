/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_keystroke.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 18:02:22 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/26 17:08:50 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	ft_chrmatch(char *str)
{
	static ssize_t	match[] = {};
	int				i;

	i = 0;
	while (match[i])
	{
		if (((ssize_t *)(str))[0] == match[i])
			return (i);
		i++;
	}
	return (0);
}

void		listen_keystroke(t_cfg *cfg)
{
	char		buffer[8];
	int			el;
	static void	(*f[])(t_dlist **lst) = {};

	ft_memset(buffer, 0, 8);
	while (read(0, buffer, 8) != -1)
	{
		el = ft_chrmatch(buffer);
		f[el](lst);
		render(find_first(lst), 0);
		ft_memset(buffer, 0, 8);
	}
}
