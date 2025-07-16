/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:47:48 by alearroy          #+#    #+#             */
/*   Updated: 2025/02/19 19:00:37 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_memory(char **dst, int i)
{
	while (--i >= 0)
		free(dst[i]);
	free(dst);
}

static int	numstring(char const *s1, char c)
{
	int	count;
	int	check;
	int	i;

	count = 0;
	i = 0;
	check = 0;
	if (s1[i] == '\0')
		return (0);
	while (s1[i])
	{
		if (s1[i] != c && check == 0)
		{
			check = 1;
			count++;
		}
		else if (s1[i] == c)
			check = 0;
		i++;
	}
	return (count);
}

static void	charstring(char const *s, int *start, int *end, char c)
{
	while (s[*start] == c)
		*start += 1;
	*end = *start;
	while (s[*end] && s[*end] != c)
		*end += 1;
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	int		i;
	int		start;
	int		end;

	i = 0;
	start = 0;
	dst = (char **)malloc(sizeof(char *) * (numstring(s, c) + 1));
	if (!s || !dst)
		return (NULL);
	while (s[start])
	{
		charstring(s, &start, &end, c);
		if (s[end] == c || end > start)
		{
			dst[i] = ft_substr(s, start, end - start);
			if (!dst[i])
				return (free_memory(dst, i), NULL);
			start = end;
			i++;
		}
	}
	dst[i] = NULL;
	return (dst);
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
		free(split[i++]);
	free(split);
}
