/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:51:38 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/14 18:43:36 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*make_line(char **buff)
{
	char	*line;
	char	*temp;
	size_t	newline_position;

	if (!buff || !*buff)
		return (NULL);
	newline_position = 0;
	while ((*buff)[newline_position] && (*buff)[newline_position] != '\n')
		newline_position++;
	if ((*buff)[newline_position] == '\n')
	{
		line = ft_substr(*buff, 0, newline_position + 1);
		temp = ft_substr(*buff, newline_position + 1, ft_strlen(*buff) - newline_position - 1);
		free(*buff);
		*buff = temp;
	}
	else
	{
		line = ft_substr(*buff, 0, ft_strlen(*buff));
		free(*buff);
		*buff = NULL;
	}
	return (line);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	char	*temp;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = 0;
	s2_len = 0;
	while (s1[s1_len++]);
	while (s2[s2_len++]);
	str = malloc(s1_len + s2_len + 1);
	if (!str)
		return (NULL);
	temp = str;
	while (*s1)
		*temp++ = *s1++;
	while (*s2)
		*temp++ = *s2++;
	*temp = '\0';
	return (str);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (*s++)
		i++;
	return (i);
}

char	*ft_strchr(char *s, char c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (*s == c)
		return (s);
	return (NULL);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	char	*src;
	char	*dest;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (malloc(1));
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	src = s + start;
	dest = str;
	while (len-- && *src)
		*dest++ = *src++;
	*dest = '\0';
	return (str);
}
