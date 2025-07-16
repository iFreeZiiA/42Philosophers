/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:27:16 by alearroy          #+#    #+#             */
/*   Updated: 2024/09/28 16:14:11 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*node;

	start = NULL;
	while (lst)
	{
		node = ft_lstnew(0);
		if (!node)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		node->content = f(lst->content);
		ft_lstadd_back(&start, node);
		lst = lst->next;
	}
	return (start);
}
