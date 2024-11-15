/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:51:48 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/15 11:39:36 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

char	*join_n_shift(char *s1, char *s2);
char	*get_next_line(int fd);
size_t	strlen_nl(char *str);
void	mv_buffer_left(char *buffer, size_t buffer_len);
char	*join_r_to_nl(char *dest, char *src, size_t len);

#endif