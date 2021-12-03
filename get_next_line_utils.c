/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:23:38 by hohnuki           #+#    #+#             */
/*   Updated: 2021/12/03 21:28:46 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
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
	return (NULL);
}

void	ft_substr_alter(char *s, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && s[start] != '\0')
	{
		s[i] = s[start];
		i++;
		start++;
	}
	s[i] = '\0';
}

static void	*ft_memset(void *str, int c, size_t size)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	value;

	i = 0;
	ptr = (unsigned char *)str;
	value = (unsigned char)c;
	while (i < size)
	{
		ptr[i] = value;
		i++;
	}
	return (str);
}

static void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_calloc(size_t n, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!n || !size)
	{
		n = 1;
		size = 1;
	}
	ptr = (char *)malloc(size * n);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (size * n));
	return ((void *)ptr);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!size)
		return (ft_strlen(src));
	else
	{
		while (i < (size - 1) && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		return (ft_strlen(src));
	}
}

char	*ft_strcat(char *dest, const char *src)
{
	unsigned int	num1;
	unsigned int	num2;

	num1 = 0;
	num2 = 0;
	while (dest[num1] != '\0')
		num1++;
	while (src[num2] != '\0')
	{
		dest[num1] = src[num2];
		num1++;
		num2++;
	}
	dest[num1] = '\0';
	return (dest);
}

