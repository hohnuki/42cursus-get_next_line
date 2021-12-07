/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnukihiroki <ohnukihiroki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:23:09 by hohnuki           #+#    #+#             */
/*   Updated: 2021/12/08 00:52:41 by ohnukihirok      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char	*memo)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!memo[i])
		return (NULL);
	while (memo[i] != '\0' && memo[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));//i+2?
	if (!str)
		return (NULL);
	i = 0;
	while (memo[i] != '\0' && memo[i] != '\n')
	{
		str[i] = memo[i];
		i++;
	}
	if (memo[i] == '\n')
	{
		str[i] = memo[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_memo(char *memo)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	while (memo[i] != '\0' && memo[i] != '\n')
		i++;
	if (!memo[i])
	{
		free (memo);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(memo) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (memo[i] != '\0')
	{
		str[j] = memo[i];
		j++;
		i++;
	}
	str[j] = '\0';
	free(memo);
	return (str);
}

char	*ft_read_and_memo(int fd, char *memo)
{
	char	*buf;
	ssize_t	read_ret;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(buf))
		return (NULL);
	read_ret = 1;
	while (!ft_strchr(memo, '\n') && read_ret != 0)
	{
		read_ret = read(fd, buf, BUFFER_SIZE);
		if (read_ret == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_ret] = '\0';
		memo = ft_strjoin(memo, buf);
	}
	free(buf);
	return (memo);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char *memo;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	memo = ft_read_and_memo(fd, memo);
	if (!memo)
		return (NULL);
	line = ft_get_line(memo);
	memo = ft_memo(memo);
	return (line);
}
