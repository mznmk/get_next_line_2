/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:55:24 by mmizuno           #+#    #+#             */
/*   Updated: 2022/03/11 12:13:36 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	// [ variables ]
	char	*line;
	int 	fd[FD_MAX];
	int		reading;

	// [ execute test ]
	printf("[ BUFFER_SIZE %d ]\n", BUFFER_SIZE);
	// < read line from stdin >
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
	// < read line from file >
	// else if (argc == 2)
	// {
	// 	// open file
	// 	fd = open(argv[1], O_RDONLY);
	// 	if (fd == -1)
	// 		return -1;
	// 	else
	// 		printf("OPEN |%4d|\n", fd);
	// 	// read line from file
	// 	while (42)
	// 	{
	// 		line = get_next_line(fd);
	// 		printf("FILE |%4d|%14p|%s\n", fd, line, line);
	// 		if (!line)
	// 			break;
	// 		else
	// 			free(line);
	// 	}
	// 	// close file
	// 	close(fd);
	// 	printf("CLOSE|%4d|\n", fd);
	// }
	else if (2 <= argc && argc <= FD_MAX+1)
	{
		// open file
		for (int i = 0; i <= argc - 2; i++)
		{
			fd[i] = open(argv[i+1], O_RDONLY);
			// failure
			if (fd[i] == -1)
			{
				for (int j = i-1; 0 <= j; j--)
					close(fd[j]);
				return -1;
			}
			else
				printf("OPEN |%4d|\n", fd[i]);
		}
		// read from file
		reading = 1;	// 1: reading / 0: not reading
		while (reading)
		{
			reading = 0;
			for (int i = 0; i <= argc - 2; i++)
			{
				// read from file
				line = get_next_line(fd[i]);
				// print read line
				printf("FILE |%4d|%14p|%s\n", fd[i], line, line);
				// deallocated memory
				if (line)
				{
					free(line);
					reading |= 1;	// be reading now ...
				}
			}
		}
		// close file
		for (int i = 0; i <= argc - 2; i++)
		{
			close(fd[i]);
			printf("CLOSE|%4d|\n", fd[i]);
		}
	}

	// [ return ]
	return 0;
}