/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:51:22 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/15 11:32:41 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes;

	line = NULL;
	bytes = 1;
	while (!(fd < 0 || BUFFER_SIZE <= 0) && bytes > 0)
	{
		if (*buffer)
		{
			line = join_n_shift(line, buffer);
			if (!line || line[strlen_nl(line) - 1] == '\n')
				break ;
		}
		else
		{
			bytes = read(fd, buffer, BUFFER_SIZE);
			if (bytes == -1)
				return (free(line), NULL);
			buffer[bytes] = '\0';
		}
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

// 	printf("\n");
// 	fd = open("test.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	count = 1;
// 	while (line)
// 	{
// 		printf("[%d]%s", count++, line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	printf("\n");
// 	close(fd);
// 	return (0);
// }