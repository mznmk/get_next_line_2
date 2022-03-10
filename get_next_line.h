/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:01:37 by mmizuno           #+#    #+#             */
/*   Updated: 2022/03/10 16:39:53 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// ================================= const ================================== //

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	32
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

// ========================= prototype declaration ========================== //

// get_next_line_util.c


// get_next_line.c
char	*get_next_line(int fd);

#endif