/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:51:38 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/14 21:04:13 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cat_n_shift(char *line, char *buffer)
{
	char	*new_line;
	size_t	line_len;
	size_t	buffer_len;

	line_len = strlen_nl(line, 0);
	buffer_len = strlen_nl(buffer, '\n');
	new_line = malloc(line_len + buffer_len + 1);
	if (!new_line)
		return (free(line), NULL);
	copy(new_line, line, line_len);
	copy(new_line + line_len, buffer, buffer_len);
	new_line[line_len + buffer_len] = '\0';
	free(line);
	mv_buffer_left(buffer, buffer_len);
	return (new_line);
}

size_t	strlen_nl(char *str, char match)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (*str && *str != match && *str != '\n')
	{
		len++;
		str++;
	}
	if (*str == '\n')
		len++;
	return (len);
}

void	copy(char *dest, const char *src, size_t len)
{
	while (len--)
		*dest++ = *src++;
}

void	mv_buffer_left(char *buffer, size_t buffer_len)
{
	char	*start;

	start = buffer + buffer_len;
	while (*start)
		*buffer++ = *start++;
	*buffer = '\0';
}
