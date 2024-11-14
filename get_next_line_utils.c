/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:51:38 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/14 21:16:14 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	strlen_nl(char *str, char match)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] && str[len] != match && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	return (len);
}

char	*cat_n_shift(char *line, char *buffer)
{
	char	*new_line;
	char	*dest;
	char	*src;
	size_t	line_len;
	size_t	buffer_len;

	line_len = strlen_nl(line, 0);
	buffer_len = strlen_nl(buffer, '\n');
	new_line = malloc(line_len + buffer_len + 1);
	if (!new_line)
		return (free(line), NULL);
	dest = new_line;
	src = line;
	while (line_len--)
		*dest++ = *src++;
	src = buffer;
	while (buffer_len--)
		*dest++ = *src++;
	*dest = '\0';
	free(line);
	mv_buffer_left(buffer, src);
	return (new_line);
}

void	mv_buffer_left(char *buffer, char *src)
{
	while (*src)
		*buffer++ = *src++;
	*buffer = '\0';
}
