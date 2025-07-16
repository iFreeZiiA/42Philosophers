/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:04:56 by alearroy          #+#    #+#             */
/*   Updated: 2024/09/17 16:08:44 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lendst;
	size_t	lensrc;
	size_t	cont;

	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	if (size <= lendst)
		return (lensrc + size);
	cont = lendst;
	while (*src != '\0' && cont < (size - 1))
		*(dst + cont++) = *src++;
	*(dst + cont) = '\0';
	return (lendst + lensrc);
}
