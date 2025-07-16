/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:14:00 by alearroy          #+#    #+#             */
/*   Updated: 2025/02/04 17:13:16 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_gn_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == (char)c)
			return (++i);
		i++;
	}
	return (0);
}

void	free_str(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
}

char	*ft_strdup(const char *str)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = (char *)malloc((sizeof(char) * (ft_strlen(str) + 1)));
	if (dup == NULL)
		return (NULL);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	char	*str;
	int		len1;
	int		len2;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
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
	free_str(&s1);
	return (str);
}
