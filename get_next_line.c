/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 23:27:01 by juhanse           #+#    #+#             */
/*   Updated: 2024/11/27 14:27:02 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_stash_line(char *tmp, int end_line)
{
	int		len;
	char	*buffer;

	len = ft_strlen(tmp) - end_line;
	if (len <= 0)
	{
		free(tmp);
		return (NULL);
	}
	buffer = ft_substr(tmp, end_line, len);
	free(tmp);
	return (buffer);
}

static char	*ft_get_line(char *tmp, int *next)
{
	int		i;
	char	*line;

	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\n')
		*next = i + 1;
	else
	{
		*next = i;
		if (i == 0 && tmp[i] == '\0')
			return (NULL);
	}
	line = ft_substr(tmp, 0, *next);
	return (line);
}

static char	*ft_new_line(int fd, char *buffer, char *tmp)
{
	int		read_bytes;
	char	*new_tmp;

	read_bytes = 1;
	while (!ft_strchr(tmp, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(buffer);
			free(tmp);
			return (NULL);
		}
		if (read_bytes == 0)
			break ;
		buffer[read_bytes] = '\0';
		new_tmp = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = new_tmp;
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	int			end_line;
	char		*buffer;
	char		*line;
	static char	*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!tmp)
		tmp = ft_strdup("");
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	tmp = ft_new_line(fd, buffer, tmp);
	free(buffer);
	if (!tmp)
		return (NULL);
	line = ft_get_line(tmp, &end_line);
	tmp = ft_stash_line(tmp, end_line);
	return (line);
}
