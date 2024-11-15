/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:51:38 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/15 17:43:51 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	len_to_nl(char *str)
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

char	*merge_and_shift(char *line, char *stash)
{
	char	*new_line;
	char	*temp;
	size_t	line_len;
	size_t	stash_len;

	line_len = len_to_nl(line);
	stash_len = len_to_nl(stash);
	new_line = malloc(line_len + stash_len + 1);
	if (!new_line)
		return (free(line), NULL);
	temp = new_line;
	temp = copy_to_nxtline(temp, line, line_len);
	temp = copy_to_nxtline(temp, stash, stash_len);
	*temp = '\0';
	free(line);
	mv_stash_left(stash, stash_len);
	return (new_line);
}

void	mv_stash_left(char *stash, size_t stash_len)
{
	char	*after_nl;

	after_nl = stash + stash_len;
	while (*after_nl)
		*stash++ = *after_nl++;
	*stash = '\0';
}

char	*copy_to_nxtline(char *nxt_line, char *str, size_t len)
{
	while (len--)
		*nxt_line++ = *str++;
	return (nxt_line);
}
