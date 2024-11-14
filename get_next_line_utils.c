/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:51:38 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/14 18:20:48 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*make_line(char **buff)
{
	char	*line;
	char	*temp;
	char	*newline_pos;

	if (!buff || !*buff)
		return (NULL);
	newline_pos = ft_strchr(*buff, '\n');
	if (newline_pos)
	{
		line = ft_substr(*buff, 0, newline_pos - *buff + 1);
		temp = ft_substr(newline_pos + 1, 0, ft_strlen(newline_pos + 1));
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
	while (s[i])
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
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (malloc(1));
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
