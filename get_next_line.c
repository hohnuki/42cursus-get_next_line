/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnukihiroki <ohnukihiroki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:23:09 by hohnuki           #+#    #+#             */
/*   Updated: 2021/12/02 18:47:26 by ohnukihirok      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	find_newline_ex(char *buff, char *save)
{
	size_t	i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
		{
			if (save != NULL && (ft_strlen(save) + i) <= ft_strlen(buff))
				i += ft_strlen(save);
			return (i + 1);
		}
		i++;
	}
	return (0);
}

static int	find_newline(char *buff)
{
	size_t	i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
			return (i);
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
		if (save != NULL)
		{
			line = save;
			save = NULL;
		}
		if (!line)
			tmp = ft_strdup(buff);
		else
			tmp = ft_strjoin(line, buff);
		if (line)
			free(line);
		line = tmp;
		if (ft_strchr(buff, '\n'))
		{
			save = ft_substr(buff, find_newline_ex(buff, save), BUFFER_SIZE);
			line[find_newline(line)] = '\n';
			break ;
		}
	}
	return (line);
}
