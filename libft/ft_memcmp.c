/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:27:03 by alearroy          #+#    #+#             */
/*   Updated: 2024/09/20 10:32:58 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *dst, const void *str, size_t n)
{
	unsigned char	*str2;
	unsigned char	*dst2;

	dst2 = (unsigned char *)dst;
	str2 = (unsigned char *)str;
	while (n--)
		if (*dst2++ != *str2++)
			return (*(--dst2) - *(--str2));
	return (0);
}
