/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:51:38 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/15 11:40:22 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	strlen_nl(char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	return (len);
}

char	*join_n_shift(char *line, char *buffer)
{
	char	*new_line;
	char	*iter_p;
	size_t	line_len;
	size_t	buffer_len;

	line_len = strlen_nl(line);
	buffer_len = strlen_nl(buffer);
	new_line = malloc(line_len + buffer_len + 1);
	if (!new_line)
		return (free(line), NULL);
	iter_p = new_line;
	iter_p = join_r_to_nl(iter_p, line, line_len);
	iter_p = join_r_to_nl(iter_p, buffer, buffer_len);
	*iter_p = '\0';
	free(line);
	mv_buffer_left(buffer, buffer_len);
	return (new_line);
}

void	mv_buffer_left(char *buffer, size_t buffer_len)
{
	char	*after_nl;

	after_nl = buffer + buffer_len;
	while (*after_nl)
		*buffer++ = *after_nl++;
	*buffer = '\0';
}

char	*join_r_to_nl(char *n_line, char *line_or_buff, size_t len)
{
	while (len--)
		*n_line++ = *line_or_buff++;
	return (n_line);
}
