/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:15:05 by alearroy          #+#    #+#             */
/*   Updated: 2024/09/27 12:58:16 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_number(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 9)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	long	m;

	m = (long)n;
	len = len_number(m);
	result = (char *)malloc(sizeof(char) * len + 1);
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	if (m < 0)
	{
		result[0] = '-';
		m *= -1;
	}
	else if (m == 0)
		result[0] = '0';
	while (m > 0)
	{
		result[--len] = (m % 10) + '0';
		m /= 10;
	}
	return (result);
}
