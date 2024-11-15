/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:51:38 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/15 12:17:53 by paude-so         ###   ########.fr       */
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

char	*cat_n_shift(char *line, char *stash)
{
	char	*new_line;
	char	*temp;
	size_t	line_len;
	size_t	stash_len;

	line_len = strlen_nl(line);
	stash_len = strlen_nl(stash);
	new_line = malloc(line_len + stash_len + 1);
	if (!new_line)
		return (free(line), NULL);
	temp = new_line;
	temp = cat_str_to_nl(temp, line, line_len);
	temp = cat_str_to_nl(temp, stash, stash_len);
	*temp = '\0';
	free(line);
	mv_buffer_left(stash, stash_len);
	return (new_line);
}

void	mv_buffer_left(char *stash, size_t stash_len)
{
	char	*after_nl;

	after_nl = stash + stash_len;
	while (*after_nl)
		*stash++ = *after_nl++;
	*stash = '\0';
}

char	*cat_str_to_nl(char *n_line, char *str, size_t len)
{
	while (len--)
		*n_line++ = *str++;
	return (n_line);
}
