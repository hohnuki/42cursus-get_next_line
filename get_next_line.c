/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:23:09 by hohnuki           #+#    #+#             */
/*   Updated: 2021/12/08 22:57:01 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get_line(char	*keep)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!keep[i])
		return (NULL);
	while (keep[i] != '\0' && keep[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (keep[i] != '\0' && keep[i] != '\n')
	{
		str[i] = keep[i];
		i++;
	}
	if (keep[i] == '\n')
	{
		str[i] = keep[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_save(char *keep)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	while (keep[i] != '\0' && keep[i] != '\n')
		i++;
	if (!keep[i])
	{
		free (keep);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(keep) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (keep[i] != '\0')
	{
		str[j] = keep[i];
		j++;
		i++;
	}
	str[j] = '\0';
	free(keep);
	return (str);
}

static char	*ft_read_and_save(int fd, char *keep)
{
	char	*buf;
	ssize_t	read_ret;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(buf))
		return (NULL);
	read_ret = 1;
	while (!ft_strchr(keep, '\n') && read_ret != 0)
	{
		read_ret = read(fd, buf, BUFFER_SIZE);
		if (read_ret == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_ret] = '\0';
		keep = ft_strjoin(keep, buf);
		if (!keep)
			break ;
	}
	free(buf);
	return (keep);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*keep;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	keep = ft_read_and_save(fd, save);
	if (!keep)
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	line = ft_get_line(keep);
	save = ft_save(keep);
	return (line);
}
