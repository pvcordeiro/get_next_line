/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:51:38 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/15 11:07:09 by paude-so         ###   ########.fr       */
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
	char	*temp;
	size_t	line_len;
	size_t	buffer_len;

	line_len = strlen_nl(line, 0);
	buffer_len = strlen_nl(buffer, '\n');
	new_line = malloc(line_len + buffer_len + 1);
	if (!new_line)
		return (free(line), NULL);
	temp = new_line;
	temp = copy_to(temp, line, line_len);
	temp = copy_to(temp, buffer, buffer_len);
	*temp = '\0';
	free(line);
	mv_buffer_left(buffer, buffer + buffer_len);
	return (new_line);
}

void	mv_buffer_left(char *buffer, char *src)
{
	while (*src)
		*buffer++ = *src++;
	*buffer = '\0';
}

char	*copy_to(char *dest, const char *src, size_t len)
{
	while (len--)
		*dest++ = *src++;
	return (dest);
}
