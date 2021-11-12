/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:23:38 by hohnuki           #+#    #+#             */
/*   Updated: 2021/11/12 19:59:04 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	ft_strcpy(str, s1);
	return (str);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char		*str;
	size_t		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (*s1 != '\0')
	{
		str[i] = *s1++;
		i++;
	}
	while (*s2 != '\0')
	{
		str[i] = *s2++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	i = 0;
	while (i <= len)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
