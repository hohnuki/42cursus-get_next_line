/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:23:09 by hohnuki           #+#    #+#             */
/*   Updated: 2021/12/07 03:49:25 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char	*save)
{
	int		i;
	char	*s;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
	{
		s[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		s[i] = save[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_save(char *save)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free (save);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (save[i] != '\0')
	{
		s[c] = save[i];
		c++;
		i++;
	}
	s[c] = '\0';
	free(save);
	return (s);
}

char	*ft_read_and_save(int fd, char *save)
{
	char	*buf;
	ssize_t	read_bytes;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(buf))
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(save, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_bytes] = '\0';
		save = ft_strjoin(save, buf);
	}
	free(buf);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char *save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_read_and_save(fd, save);
	if (!save)
		return (NULL);
	line = ft_get_line(save);
	save = ft_save(save);
	return (line);
}
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

//static int	find_newline(char *buf)
//{
//	size_t	i;

//	i = 0;
//	while (buf[i] != '\0')
//	{
//		if (buf[i] == '\n')
//			return (i + 1);
//		i++;
//	}
//	return (0);
//}

//char	*get_next_line(int fd)
//{
//	char		*line;
//	char		*buf;
//	static char	*memo;
//	ssize_t		i;

//	i = 0;
//	if (fd < 0 || BUFFER_SIZE <= 0)
//		return (NULL);
//	buf = (char *)calloc((BUFFER_SIZE + 1), sizeof(char));
//	if (!buf)
//		return (NULL);
//	while ((i = read(fd, buf, BUFFER_SIZE)) > 0)
//	{
//		if (!memo)
//			memo = ft_strdup(buf);
//		else
//			ft_strcat(memo, buf);
//		if (ft_strchr(memo, '\n'))
//		{
//			line = ft_strdup(memo);
//			line[find_newline(memo)] = '\0';
//			memo = ft_substr(memo, find_newline(memo), ft_strlen(memo));
//			free (buf);
//			return (line);
//		}
//		i = 0;
//	}
//	line = memo;
//	memo = NULL;
//	free (buf);
//	return (line);
//}

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
