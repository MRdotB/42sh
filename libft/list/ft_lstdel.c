/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 14:57:29 by bchaleil          #+#    #+#             */
/*   Updated: 2016/01/10 15:26:36 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*current;

	if (alst)
	{
		current = *alst;
		while (current)
		{
			if (del)
				del(current->content, current->content_size);
			free(current);
			current = current->next;
		}
	}
	*alst = NULL;
}
