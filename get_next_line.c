/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:23:09 by hohnuki           #+#    #+#             */
/*   Updated: 2021/11/08 19:43:02 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	get_next_line(int fd, char **line)
{
	int	ret;
	char	buf[BUFFER_SIZE + 1];
	char	*tmp;

	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!*line)
			tmp = ft_strdup(buf);
		else
			tmp = ft_strjoin(*line, buf);
		if (*line)
			free(*line);
		*line = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret > 0)
		ret = 1;
	return (ret);
}

int	main(void)
{
	int	fd;
	char *line;

	fd = open("file", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		printf("%s\n", line);
	return (0);
}
