/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:13:39 by alearroy          #+#    #+#             */
/*   Updated: 2025/02/19 18:35:52 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*clean_buff(char *buffer)
{
	char	*temp_buff;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp_buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!temp_buff)
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	while (buffer[i])
		temp_buff[j++] = buffer[i++];
	temp_buff[j] = '\0';
	free_str(&buffer);
	buffer = ft_strdup(temp_buff);
	free_str(&temp_buff);
	return (buffer);
}

void	copy_str(char *buffer, char *next_str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[j])
	{
		if (buffer[j] == '\n')
		{
			next_str[i++] = '\n';
			next_str[i] = '\0';
			return ;
		}
		next_str[i++] = buffer[j++];
	}
	next_str[i] = '\0';
}

char	*ft_readbuffer(char *buffer, int fd)
{
	char	*r_buffer;
	int		nb_read;

	nb_read = 1;
	r_buffer = (char *)ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!r_buffer)
		return (NULL);
	while (nb_read > 0 && !ft_gn_strchr(r_buffer, '\n'))
	{
		nb_read = read(fd, r_buffer, BUFFER_SIZE);
		if (nb_read <= 0)
		{
			if (!buffer || !buffer[0] || nb_read == -1)
			{
				free_str(&r_buffer);
				return (free_str(&buffer), NULL);
			}
		}
		r_buffer[nb_read] = '\0';
		if (!buffer && nb_read > 0)
			buffer = ft_strdup(r_buffer);
		else if (nb_read > 0)
			buffer = ft_strjoin(buffer, r_buffer);
	}
	return (free_str(&r_buffer), buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	int			len_buffer;
	char		*next_str;

	len_buffer = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free_str(&buffer);
		return (NULL);
	}
	if (!buffer || !ft_gn_strchr(buffer, '\n'))
		buffer = ft_readbuffer(buffer, fd);
	if (!buffer)
		return (NULL);
	while (buffer[len_buffer] && buffer[len_buffer] != '\n')
		len_buffer++;
	next_str = (char *)malloc(sizeof(char) * (len_buffer + 2));
	if (!next_str)
		return (NULL);
	copy_str(buffer, next_str);
	buffer = clean_buff(buffer);
	return (next_str);
}

/* int	main(void)
{
	int		fd;
	char	*buffer;
	int		count;

	count = 1;
	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while (1)
	{
		buffer = get_next_line(fd);
		if (!buffer || buffer == NULL)
			break ;
		printf("%d : %s", count, buffer);
		count++;
		free(buffer);
	}
	close(fd);
	return (0);
} */
