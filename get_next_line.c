/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:01:48 by mmizuno           #+#    #+#             */
/*   Updated: 2022/03/11 06:22:08 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_buffer(char *buff1, char*buff2)
{
	char	*buff;
	long	len1;
	long	len2;
	int		i;

	len1 = ft_strlen(buff1);
	len2 = ft_strlen(buff2);
	buff = allocate_memory(len1 + len2);
	if (!buff)
		return (NULL);
	i = -1;
	while (buff1[++i])
		buff[i] = buff1[i];
	i = -1;
	while (buff2[++i])
		buff[len1+i] = buff2[i];

	free(buff1);

	return buff;
}

char	*split_buffer(char **buff)
{
	char	*newline;
	char	*newbuff;
	long	index;
	char	*temp;
	if (!*buff)
		return (NULL);
	index = find_index(*buff, '\n');
// printf("index:%ld\n", index);
	if (index < 0)
	{
// printf("ahoaho\n");
		newline = ft_substr(*buff, 0, ft_strlen(*buff));
		newbuff = allocate_memory(0);
// printf("newline:%s\n", newline);
// printf("newbuff:%s\n", newbuff);
	}
	else
	{
// printf("bokeboke\n");
		newline = ft_substr(*buff, 0, index);
		newbuff = ft_substr(*buff, index + 1, ft_strlen(*buff) - (index + 1));
// printf("newline:%s\n", newline);
// printf("newbuff:%s\n", newbuff);
	}
	free(*buff);
	*buff = newbuff;
	return (newline);
}

char	*read_buffer(int fd, char *buff)
{
	long	status;
	char	*temp;

	temp = allocate_memory(BUFFER_SIZE);
	if (!temp)
		return (NULL);
	status = 1;
	while (find_index(temp, '\n') == -1 && status != 0)
	{
		status = read(fd, temp, BUFFER_SIZE);
		if (status < -1)
		{
			free(temp);
			return (NULL);
		}
		temp[status] = '\0';
		buff = join_buffer(buff, temp);
		if (!buff)
		{
			free(temp);
			return (NULL);
		}
	}
// printf("buff:%s\n", buff);
// printf("temp:%s\n", temp);
	free(temp);
	return (buff);
}


char	*get_next_line(int fd)
{
	char		*line;
	static char	*buff;

	// treat error
	if (fd < 0 || BUFFER_SIZE < 1)
		return NULL;
	// allocate memory
	if (!buff)
		buff = allocate_memory(0);
	if (!buff)
		return (NULL);
	// read & join buffer
	buff = read_buffer(fd, buff);
	if (!buff)
		return (NULL);
	// split into line & buffer
	line = split_buffer(&buff);
	// return
	return line;	
}
