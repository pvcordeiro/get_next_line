/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:51:22 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/13 20:15:46 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	static char	*stat_buf;
	char		*temp_buf;
	char		*line;
	int			b_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (NULL);
	temp_buf = malloc(BUFFER_SIZE + 1);
	if (!temp_buf)
		return (NULL);
	b_read = 1;
	while (!ft_strchr(stat_buf, '\n') && b_read > 0)
	{
		b_read = read(fd, temp_buf, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(temp_buf);
			return (NULL);
		}
		temp_buf[b_read] = 0;
		stat_buf = ft_strjoin(stat_buf, temp_buf);
	}
	line = process_line(&stat_buf);
	free(temp_buf);
	return (line);
}

#include <stdio.h>
int	main(void)
{
	char	*line;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

