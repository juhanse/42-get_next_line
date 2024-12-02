/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 23:27:33 by juhanse           #+#    #+#             */
/*   Updated: 2024/12/02 20:16:38 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*ret;
	int		i;
	int		j;

	i = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	ret = malloc(sizeof(char) * (size + 1));
	if (!ret || !s1 || !s2)
		return (NULL);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	j = -1;
	while (s2[++j])
	{
		ret[i] = s2[j];
		i++;
	}
	ret[size] = 0;
	return (ret);
}

char	*ft_strchr(const char *str, int character)
{
	if (!str)
		return (NULL);
	while (*str || (char)character == '\0')
	{
		if (*str == (char)character)
			return ((char *)str);
		str++;
	}
	if (*str == character)
		return ((char *)str);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	if (!dst || !src)
		return (0);
	i = -1;
	len = ft_strlen(src);
	if (!size)
		return (len);
	while (++i < size - 1 && src[i])
		dst[i] = src[i];
	dst[i] = 0;
	return (len);
}
