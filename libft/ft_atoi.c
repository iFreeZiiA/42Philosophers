/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:23:19 by alearroy          #+#    #+#             */
/*   Updated: 2025/05/23 18:24:36 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdio.h>

static long	ft_atoicheck(const char *str, long result, int sign, int i)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > INT_MAX)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	long				result;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\t'
		|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	return ((int)ft_atoicheck(str, result, sign, i) * sign);
}

int	ft_atoi_secure(const char *str, int *error)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	*error = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		if ((sign == 1 && res > INT_MAX) || (sign == -1 && - res < INT_MIN))
		{
			*error = 1;
			return (0);
		}
		str++;
	}
	return ((int)(res * sign));
}
