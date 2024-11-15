/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:51:48 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/15 16:56:33 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define FD_MAX 1024

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*join_n_shift(char *s1, char *s2);
char	*get_next_line(int fd);
size_t	strlen_nl(char *str);
void	mv_buffer_left(char *buffer, size_t buffer_len);
char	*cat_str_to_nxtl(char *n_line, char *str, size_t len);

#endif