/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:23:09 by hohnuki           #+#    #+#             */
/*   Updated: 2021/11/12 20:22:20 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(int fd, char **line)
{
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;
	int		ret;

	ret = 0;
	while (read(fd, buff, BUFFER_SIZE) > 0)
	{
		buff[ret] = '\0';
		if (!*line)
			tmp = ft_strdup(buff);
		else
			tmp = ft_strjoin(*line, buff);
		if (*line)
			free(*line);
		*line = tmp;
		if (ft_strchr(buff, '\n'))
			break;
	}
	if (ret > 0)
		ret = 1;
	return (ret);
}

int	main(void)
{
	int	fd;
	int	i;
	char **line = NULL;

	fd = open("sample1.txt", O_RDONLY);
	i = 0;
	if (fd == -1)
		printf("file can't open\n");
	while (get_next_line(fd, line) > 0)
	{
		printf("%s\n", line[i]);
		i++;
	}
	return (0);
}
