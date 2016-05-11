/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:08:46 by bchaleil          #+#    #+#             */
/*   Updated: 2016/01/10 15:19:58 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*r;
	t_list	*current;

	if (lst == NULL || f == NULL)
		return (NULL);
	r = ft_lstnew(lst->content, lst->content_size);
	if (!(r))
		return (NULL);
	r = f(r);
	while (lst->next)
	{
		lst = lst->next;
		current = ft_lstnew(lst->content, lst->content_size);
		if (!(current))
			return (NULL);
		ft_lstpush(r, f(current));
	}
	return (r);
}
