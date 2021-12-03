/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:23:09 by hohnuki           #+#    #+#             */
/*   Updated: 2021/12/03 21:43:16 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

//static size_t	find_newline_ex(char *buf, char *save)
//{
//	size_t	i;

//	i = 0;
//	while (buf[i] != '\0')
//	{
//		if (buf[i] == '\n')
//		{
//			if (save != NULL && (ft_strlen(save) + i) <= ft_strlen(buf))
//                i += ft_strlen(save);
//			return (i + 1);
//		}
//		i++;
//	}
//	return (0);
//}

static int	find_newline(char *buf)
{
	size_t	i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*memo;
	char		*buf;

	if (!fd)
		return (NULL);
	buf = (char *)calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{
		//printf("[buf] =  %s\n", buf);
		if (!memo)
			memo = ft_strdup(buf);
		else
			ft_strcat(memo, buf);
		if (ft_strchr(memo, '\n'))
		{
			printf("[find_newline] = [%d]\n", (find_newline(memo) + 1));
			free (line);
			line = ft_strdup(memo);
			//ft_strlcpy(line, memo, find_newline(memo) + 1);
			//line = memo;
			line[find_newline(memo) + 1] = '\0';
			printf("[line] = [%s]\n", line);
			ft_substr_alter(memo, find_newline(memo), ft_strlen(memo));
			free (buf);
			return (line);
		}
	}
	line = memo;
	memo = NULL;
	free (buf);
	return (line);
}

//char	*get_next_line(int fd)
//{
//	char		*line;
//	char		*tmp;
//	static char	*save;
//	char		*buf;

//	line = NULL;
//	tmp = NULL;
//	if (fd < 0)
//		return (NULL);
//	buf = (char *)calloc(sizeof(char), BUFFER_SIZE + 1);
//	if (!buf)
//		return (NULL);
//	while (read(fd, buf, BUFFER_SIZE) > 0)
//	{
//		printf("buf = [%s]\n", buf);
//		if (save != NULL)
//			line = save;
//		if (!line)
//			tmp = ft_strdup(buf);
//		else
//			tmp = ft_strjoin(line, buf);
//		if (!tmp)
//			return (NULL);
//		if (line)
//			free(line);
//		line = tmp;
//		if (ft_strchr(buf, '\n'))
//		{
//			printf("XXXXX\n");
//			save = ft_substr(buff, find_newline_ex(buf, save), BUFFER_SIZE);
//			line[find_newline(line)] = '\0';
//			break ;
//		}
//		else
//		{
//			printf("YYYY\n");
//			save = ft_substr(buf, BUFFER_SIZE, ft_strlen(buff));
//			printf("save= [%s]\n", save);
//		}
//	}
//	free(buf);
//	return (line);
//}
