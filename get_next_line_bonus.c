/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:51:22 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/15 16:55:09 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	stash[FD_MAX][BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FD_MAX)
		return (NULL);
	line = NULL;
	bytes_read = 1;
	while (bytes_read > 0)
	{
		if (*stash[fd])
		{
			line = join_n_shift(line, stash[fd]);
			if (line && line[strlen_nl(line) - 1] == '\n')
				break ;
		}
		bytes_read = read(fd, stash[fd], BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(line), NULL);
		stash[fd][bytes_read] = '\0';
	}
	return (line);
}

// #include <stdio.h>
// #include <fcntl.h>

// int main(void)
// {
//     char *line;
//     int fd[4];
// 	int	i;
// 	int	done;

//     fd[0] = open("fd3.txt", O_CREAT | O_WRONLY, 0777);
//     	write(fd[0], "Roses are red\n"
//            "Violets are blue\n"
//            "Segmentation Fault\n"
//            "On line 32\n", 62);
//     close(fd[0]);

//     fd[1] = open("fd4.txt", O_CREAT | O_WRONLY, 0777);
//     	write(fd[1], "Roses are red\n"
//            "Violets are blue\n"
//            "Segmentation Fault\n"
//            "On line 32\n", 62);
//     close(fd[1]);

//     fd[2] = open("fd5.txt", O_CREAT | O_WRONLY, 0777);
//     	write(fd[2], "Roses are red\n"
//            "Violets are blue\n"
//            "Segmentation Fault\n"
//            "On line 32\n", 62);
//     close(fd[2]);

//     fd[3] = open("fd6.txt", O_CREAT | O_WRONLY, 0777);
//     	write(fd[3], "Roses are red\n"
//            "Violets are blue\n"
//            "Segmentation Fault\n"
//            "On line 32\n", 62);
//     close(fd[3]);
// 
// 
//     fd[0] = open("fd3.txt", O_RDONLY);
//     fd[1] = open("fd4.txt", O_RDONLY);
//     fd[2] = open("fd5.txt", O_RDONLY);
//     fd[3] = open("fd6.txt", O_RDONLY);
// 
//     while (1)
//     {
//         done = 1;
// 		i = 0;
//         while (i < 4)
//         {
//             line = get_next_line(fd[i]);
//             if (line)
//             {
//                 done = 0;
//                 printf("File Descriptor [%d]: %s", i + 3, line);
//                 free(line);
//             }
// 			i++;
//         }
// 		printf("\n");
//         if (done)
//             break;
//     }
// 
// 	close(fd[0]);
// 	close(fd[1]);
// 	close(fd[2]);
// 	close(fd[3]);
//     return (0);
// }