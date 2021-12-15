/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:23:09 by hohnuki           #+#    #+#             */
/*   Updated: 2021/12/15 21:25:49 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*store_to_save(char *save)
{
	char	*str;
	size_t	i;

	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free (save);
		return (NULL);
	}
	str = ft_substr(save, i + 1, ft_strlen(save));
	free(save);
	return (str);
}

static char	*trimming_save(char	*save)
{
	char	*str;
	size_t	i;

	if (!save[0])
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	str = ft_substr(save, 0, i + 1);
	return (str);
}

static char	*join_to_save(int fd, char *save)
{
	char	*buf;
	ssize_t	read_ret;

	if (BUFFER_SIZE == INT_MAX)
		buf = (char *)malloc (sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	else
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read_ret = NOT_EOF_OR_ERROR;
	while (!ft_strchr(save, '\n') && read_ret != 0)
	{
		read_ret = read(fd, buf, BUFFER_SIZE);
		if (read_ret == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_ret] = '\0';
		save = ft_strjoin(save, buf);
	}
	free(buf);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || INT_MAX < BUFFER_SIZE)
		return (NULL);
	save = join_to_save(fd, save);
	if (!save)
		return (NULL);
	line = trimming_save(save);
	save = store_to_save(save);
	return (line);
}
