/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:17:06 by alearroy          #+#    #+#             */
/*   Updated: 2024/10/01 18:28:35 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	flag_guessing(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
		if (set[i++] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	while (flag_guessing(set, s1[i]) && s1[i])
		i++;
	while (flag_guessing(set, s1[len - 1]) && (len - 1))
		len--;
	if (len < i)
		len = i;
	str = malloc(len - i + 1);
	if (!str)
		return (NULL);
	while (i < len)
		str[k++] = s1[i++];
	str[k] = '\0';
	return (str);
}
