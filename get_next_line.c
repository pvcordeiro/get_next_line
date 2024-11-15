/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:51:22 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/15 12:17:35 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	bytes_read = 1;
	while (bytes_read > 0)
	{
		if (*stash)
		{
			line = cat_n_shift(line, stash);
			if (!line || line[strlen_nl(line) - 1] == '\n')
				break ;
		}
		bytes_read = read(fd, stash, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(line), NULL);
		stash[bytes_read] = '\0';
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