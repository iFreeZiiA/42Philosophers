/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:44:18 by alearroy          #+#    #+#             */
/*   Updated: 2024/10/14 16:30:49 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len1;
	int		len2;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	str = (char *)malloc((sizeof(char) * (len1 + len2 + 1)));
	if (!str)
		return (NULL);
	while (len1--)
	{
		str[i] = s1[i];
		i++;
	}
	len1 = i;
	i = 0;
	while (len2--)
		str[len1++] = s2[i++];
	str[len1] = '\0';
	return (str);
}
