/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:14:28 by mmizuno           #+#    #+#             */
/*   Updated: 2022/03/11 11:18:59 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*allocate_memory(int size)
{
	char	*memory;

	size += 1;
	memory = (char *)malloc(sizeof(char) * size);
	if (!memory)
		return (NULL);
	while (size--)
		memory[size] = '\0';
	return (memory);
}

char	*deallocate_memory(char **memory)
{
	if (*memory)
		free(*memory);
	*memory = NULL;
	return (NULL);
}

long	ft_strlen(const char *s)
{
	long	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char *s, long start, long len)
{
	long	s_len;
	char	*substr;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len == 0 || s_len < start)
		return (allocate_memory(0));
	substr = allocate_memory(len);
	if (!substr)
		return (NULL);
	while (len--)
		substr[len] = s[start + len];
	return (substr);
}

long	find_index(const char *s, char c)
{
	long		i;

	i = -1;
	if (!s)
		return (i);
	while (s[++i])
	{
		if (s[i] == c)
			return (i);
	}
	return (-1);
}
