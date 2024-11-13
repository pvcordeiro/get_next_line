/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:51:38 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/13 20:15:49 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*process_line(char **str)
{
	char	*line;
	char	*temp;
	char	*remainder;

	remainder = ft_strchr(*str, '\n');
	if (remainder)
	{
		line = ft_substr(*str, 0, remainder - *str);
		temp = ft_substr(*str, remainder - *str + 1, ft_strlen(remainder + 1));
		free(*str);
		*str = temp;
	}
	else
	{
		line = ft_substr(*str, 0, ft_strlen(*str));
		free(*str);
		*str = NULL;
	}
	return (line);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	char	*temp;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	temp = str;
	while (*s1)
		*temp++ = *s1++;
	while (*s2)
		*temp++ = *s2++;
	*temp = 0;
	return (str);
}

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

char	*ft_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s++ == c)
			return (--s);
	}
	if (*s == c)
		return (s);
	return (NULL);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	char	*start_pointer;
	char	*temp;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return ("");
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	start_pointer = s + start;
	temp = str;
	while (len-- && *start_pointer)
		*temp++ = *start_pointer++;
	*temp = 0;
	return (str);
}