/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:51:22 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/10 14:57:11 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buf;
	char		*line;
	int			ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	ret = 1;
	while (!ft_strchr(str, '\n') && ret != 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[ret] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	line = ft_substr(str, 0, ft_strchr(str, '\n') - str);
	if (ft_strchr(str, '\n'))
		str = ft_strdup(ft_strchr(str, '\n') + 1);
	else
	{
		free(str);
		str = NULL;
	}
	return (line);
}
