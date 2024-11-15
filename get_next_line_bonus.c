/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:51:22 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/15 17:54:40 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	stash[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*result;
	ssize_t		read_count;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	result = NULL;
	read_count = 1;
	while (read_count > 0)
	{
		if (*stash[fd])
		{
			result = merge_and_move(result, stash[fd]);
			if (result && result[len_to_nl(result) - 1] == '\n')
				break ;
		}
		read_count = read(fd, stash[fd], BUFFER_SIZE);
		if (read_count == -1)
			return (free(result), NULL);
		stash[fd][read_count] = '\0';
	}
	return (result);
}

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

//     fd[0] = open("fd3.txt", O_RDONLY);
//     fd[1] = open("fd4.txt", O_RDONLY);
//     fd[2] = open("fd5.txt", O_RDONLY);
//     fd[3] = open("fd6.txt", O_RDONLY);

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

// 	close(fd[0]);
// 	close(fd[1]);
// 	close(fd[2]);
// 	close(fd[3]);
//     return (0);
// }