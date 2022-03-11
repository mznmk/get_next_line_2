/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:55:24 by mmizuno           #+#    #+#             */
/*   Updated: 2022/03/11 08:41:57 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	// [ variables ]
	char	*line;
	// int 	fd[MAX_FD];
	// int		reading;
	int 	fd;

	// [ execute test ]
	printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
	// read from stdin
	if (argc == 1)
	{
		while (42)
		{
		// read from stdin
			line = get_next_line(0);
			// print read line
			printf("STDIN|   0|%14p|%s\n", line, line);
			// deallocate memory
			if (line)
				free(line);
			else
				break;
		}
	}
	// read from file
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (42)
		{
			line = get_next_line(fd);
			printf("FILE|%4d|%14p|%s\n", fd, line, line);
			if (!line)
				break;
			else {
				free(line);
			}
		}
		close(fd);
	}
	// else if (2 <= argc && argc <= MAX_FD+1)
	// {
	// 	// open file
	// 	for (int i = 0; i <= argc - 2; i++)
	// 	{
	// 		fd[i] = open(argv[i+1], O_RDONLY);
	// 		// failure
	// 		if (fd[i] == -1)
	// 		{
	// 			for (int j = i-1; 0 <= j; j--)
	// 				close(fd[j]);
	// 			return -1;
	// 		}
	// 	}
	// 	// read from file
	// 	reading = 1;	// 1: reading / 0: not reading
	// 	while (reading)
	// 	{
	// 		reading = 0;
	// 		for (int i = 0; i <= argc - 2; i++)
	// 		{
	// 			// read from file
	// 			line = get_next_line(fd[i]);
	// 			// print read line
	// 			printf("FILE|%4d|%s\n", fd[i], line);
	// 			// deallocated memory
	// 			if (line)
	// 			{
	// 				free(line);
	// 				reading |= 1;	// be reading ...
	// 			}
	// 		}
	// 	}
	// 	// close file
	// 	for (int i = 0; i <= argc - 2; i++)
	// 		close(fd[i]);
	// }

	// [ return ]
	return 0;
}