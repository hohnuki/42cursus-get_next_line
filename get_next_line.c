/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:23:09 by hohnuki           #+#    #+#             */
/*   Updated: 2021/12/01 21:39:20 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	find_newline(char *buff, char *save)
{
	size_t	i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
		{
			if (save != NULL)
				i += ft_strlen(save);
			//printf("[ret] : %zu\n", i);
			return (i + 1);
		}
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*tmp;
	static char	*save;
	char		buff[BUFFER_SIZE + 1];

	line = NULL;
	if (fd < 0)
		return (NULL);
	while (read(fd, buff, BUFFER_SIZE) > 0)
	{
		printf("[buff] : %s\n", buff);
		if (save != NULL)
			line = save;
		if (!line)
			tmp = ft_strdup(buff);
		else
			tmp = ft_strjoin(line, buff);
		if (line)
			free(line);
		line = tmp;
		if (ft_strchr(buff, '\n'))
		{
			save = ft_substr(buff, find_newline(buff, save), BUFFER_SIZE);
			line[find_newline(buff, save)] = '\0';
			printf("[save] : %s, [find_nl] : %zu, [BUFFER_SIZE] : %d\n", save, find_newline(buff, save), BUFFER_SIZE);
			break ;
		}
		else
		{
			save = ft_substr(buff, find_newline(buff, save), BUFFER_SIZE);
			printf("[save] : %s, [find_nl] : %zu, [BUFFER_SIZE] : %d\n", save, find_newline(buff, save), BUFFER_SIZE);
		}
	}
	return (line);
}
