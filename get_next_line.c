/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:51:22 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/15 17:45:02 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	char		*result;
	ssize_t		read_count;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	result = NULL;
	read_count = 1;
	while (read_count > 0)
	{
		if (*stash)
		{
			result = merge_and_shift(result, stash);
			if (result && result[len_to_nl(result) - 1] == '\n')
				break ;
		}
		read_count = read(fd, stash, BUFFER_SIZE);
		if (read_count == -1)
			return (free(result), NULL);
		stash[read_count] = '\0';
	}
	return (result);
}

// #include <stdio.h>
// #include <fcntl.h>
// int	main(void)
// {
// 	char	*line;
// 	size_t	fd;

// 	fd = open("test.txt", O_CREAT | O_WRONLY, 0777);
// 	write(fd, "Roses are red\n"
//            "Violets are blue\n"
//            "Segmentation Fault\n"
//            "On line 32\n", 62);
// 	close(fd);
// 	fd = open("test.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }