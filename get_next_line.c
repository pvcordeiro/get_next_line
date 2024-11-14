/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:51:22 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/14 12:20:24 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*static_buffer;
	char		*temp_buffer;
	char		*new_buffer;
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!static_buffer)
	{
		if (!(static_buffer = malloc(1)))
			return (NULL);
		*static_buffer = '\0';
	}
	if (!(temp_buffer = malloc(BUFFER_SIZE + 1)))
	{
		free(static_buffer);
		static_buffer = NULL;
		return (NULL);
	}
	bytes_read = 1;
	while (!ft_strchr(static_buffer, '\n') && bytes_read > 0)
	{
		if ((bytes_read = read(fd, temp_buffer, BUFFER_SIZE)) == -1)
		{
			free(temp_buffer);
			free(static_buffer);
			static_buffer = NULL;
			return (NULL);
		}
		temp_buffer[bytes_read] = '\0';
		if (!(new_buffer = ft_strjoin(static_buffer, temp_buffer)))
		{
			free(temp_buffer);
			free(static_buffer);
			static_buffer = NULL;
			return (NULL);
		}
		free(static_buffer);
		static_buffer = new_buffer;
	}
	free(temp_buffer);
	if (!bytes_read && !static_buffer[0])
	{
		free(static_buffer);
		static_buffer = NULL;
		return (NULL);
	}
	if (!(line = make_line(&static_buffer)))
	{
		free(static_buffer);
		static_buffer = NULL;
		return (NULL);
	}
	return (line);
}

// #include <stdio.h>
// #include <fcntl.h>
// int	main(void)
// {
// 	char	*line;
// 	int		fd;
// 	int	count;

// 	fd = open("test.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	count = 1;
// 	while (line)
// 	{
// 		printf("[%d]%s", count++, line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }