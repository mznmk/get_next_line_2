/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:01:48 by mmizuno           #+#    #+#             */
/*   Updated: 2022/03/11 12:09:59 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*validate_buffer(char *buff)
{
	long	len;

	if (!buff)
		return (NULL);
	len = ft_strlen(buff);
	if (!len)
		return (deallocate_memory(&buff));
	if (buff[len - 1] == '\n')
		buff[len - 1] = '\0';
	return (buff);
}

static char	*split_buffer(char **buff)
{
	char	*newline;
	char	*newbuff;
	long	index;

	if (!*buff)
		return (NULL);
	index = find_index(*buff, '\n');
	if (index < 0)
	{
		newline = ft_substr(*buff, 0, ft_strlen(*buff));
		newbuff = allocate_memory(0);
	}
	else
	{
		newline = ft_substr(*buff, 0, index + 1);
		newbuff = ft_substr(*buff, index + 1, ft_strlen(*buff) - (index + 1));
	}
	deallocate_memory(buff);
	*buff = newbuff;
	return (newline);
}

static char	*join_buffer(char *buff1, char*buff2)
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
		buff[len1 + i] = buff2[i];
	deallocate_memory(&buff1);
	return (buff);
}

static char	*append_buffer(int fd, char *buff)
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
			return (deallocate_memory(&temp));
		temp[status] = '\0';
		buff = join_buffer(buff, temp);
		if (!buff)
			return (deallocate_memory(&temp));
	}
	deallocate_memory(&temp);
	return (buff);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffs[FD_MAX - FD_NOTUSE];
	int			index;

	if (fd)
		index = fd - FD_NOTUSE;
	else
		index = 0;
	if (fd < 0 || FD_MAX < fd || BUFFER_SIZE < 1)
		return (NULL);
	if (!buffs[index])
		buffs[index] = allocate_memory(0);
	if (!buffs[index])
		return (NULL);
	buffs[index] = append_buffer(fd, buffs[index]);
	if (!buffs[index])
		return (NULL);
	line = split_buffer(&buffs[index]);
	line = validate_buffer(line);
	return (line);
}
