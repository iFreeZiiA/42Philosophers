/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:46:09 by alearroy          #+#    #+#             */
/*   Updated: 2024/09/20 19:46:14 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*tofind == '\0' || tofind == NULL)
		return ((char *)str);
	while (str[i] != '\0' && i < n)
	{
		j = 0;
		while (tofind[j] == str[i + j] && i + j < n)
		{
			if (tofind[j + 1] == '\0')
				return ((char *)str + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
