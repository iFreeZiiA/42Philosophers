/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:51:24 by alearroy          #+#    #+#             */
/*   Updated: 2025/02/19 19:04:35 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint_ps(t_list *head_a, t_list *head_b)
{
	t_list	*temp_a;
	t_list	*temp_b;

	temp_a = head_a;
	temp_b = head_b;
	while (temp_a || temp_b)
	{
		if (temp_a)
			ft_printf("%d, Index: %d, AboveM: %d, Price :%d", temp_a->content,
				temp_a->index, temp_a->above_median, temp_a->price);
		else
			ft_printf("N				");
		if (temp_b)
			ft_printf("	%d, Index: %d, AbM: %d, Price :%d, Best :%d,Target :%d",
				temp_b->content, temp_b->index,
				temp_b->above_median, temp_b->price, temp_b->best_price,
				temp_b->target->content);
		else
			ft_printf("	N");
		if (temp_a)
			temp_a = temp_a->next;
		if (temp_b)
			temp_b = temp_b->next;
		ft_printf("\n");
	}
}
