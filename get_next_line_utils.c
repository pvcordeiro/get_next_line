/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:51:38 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/14 20:20:58 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	len_nd_match(char *str, char match)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] && str[len] != match)
		len++;
	if (str[len] == '\n')
		len++;
	return (len);
}

char	*cat_line_buffer(char *s1, char *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	s1_len = len_nd_match(s1, 0);
	s2_len = len_nd_match(s2, '\n');
	str = malloc(s1_len + s2_len + 1);
	if (!str)
		return (free(s1), NULL);
	str[s1_len + s2_len] = '\0';
	i = -1;
	while (++i < s1_len)
		str[i] = s1[i];
	i = -1;
	while (++i < s2_len)
		str[s1_len + i] = s2[i];
	free(s1);
	i = -1;
	while (s2[s2_len + ++i])
		s2[i] = s2[s2_len + i];
	s2[i] = '\0';
	return (str);
}
