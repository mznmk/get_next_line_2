/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:01:37 by mmizuno           #+#    #+#             */
/*   Updated: 2022/03/11 06:51:20 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// ================================= const ================================== //

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	10
# endif
# ifndef MAX_FD
#  define MAX_FD		1024
# endif

// ================================ library ================================= //

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include <stdio.h>			// for debug

// // ================================= struct ================================= //

// typedef struct	s_lines
// {
// 	char	*line;
// 	char	*buff;
// }				t_lines;


// ========================= prototype declaration ========================== //

// get_next_line_util.c
char	*allocate_memory(int size);
long	ft_strlen(const char *s);
long	find_index(const char *s, char c);
char	*ft_substr(char *s, long start, long len);

// get_next_line.c
char	*get_next_line(int fd);

#endif