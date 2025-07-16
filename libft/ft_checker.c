/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:39:50 by alearroy          #+#    #+#             */
/*   Updated: 2025/02/19 18:53:30 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_issign(int n)
{
	if (n == '-' || n == '+')
		return (1);
	return (0);
}

int	ft_check_push_swap(char *str)
{
	int		i;
	bool	sign;

	i = 0;
	sign = false;
	while (str[i])
	{
		if (ft_issign(str[i]) && sign == true)
			return (0);
		if (ft_issign(str[i]))
			sign = true;
		if (!ft_isdigit(str[i]) && (sign == false) && str[i] != ' ')
			return (0);
		if (str[i] == ' ')
			sign = false;
		i++;
	}
	return (1);
}

int	ft_checkdouble(t_list *head)
{
	t_list	*node;
	t_list	*temp;

	node = head;
	while (node)
	{
		temp = node->next;
		while (temp)
		{
			if (node->content == temp->content)
				return (1);
			temp = temp->next;
		}
		node = node->next;
	}
	return (0);
}
