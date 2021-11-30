/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:23:09 by hohnuki           #+#    #+#             */
/*   Updated: 2021/11/25 14:56:53 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//TODO
//前回余分に読み込まれた文字列のコンテナ
//前回余分に読み込まれた文字列を*lineに移動する処理
//余分に読み込んだ文字列を格納する処理

int	get_next_line(int fd, char **line)
{
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;
	int		return_read;

	while ((return_read = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[return_read] = '\0';
		if (!*line)
			tmp = ft_strdup(buff);
		else
			tmp = ft_strjoin(*line, buff);
		if (*line)
			free(*line);
		*line = tmp;
		printf("%s\n", buff);
		if (ft_strchr(buff, '\n'))
			break;
	}
	if (return_read > 0)
		return_read = 1;
	return (return_read);
}
