/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:47:08 by juhanse           #+#    #+#             */
/*   Updated: 2024/11/20 15:03:49 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	read_and_stash(int fd, t_list **stash, int *reloaded)
{
	char	*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_is_new_line(*stash) && *reloaded != 0)
	{
		*reloaded = (int)read(fd, buffer, BUFFER_SIZE);
		if ((!*stash))
		buffer[*reloaded] = '\0';
	}
}

char	*get_next_line(int fd)
{
	int				readed;
	char			*line;
	static t_list	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	readed = 1;
	line = NULL;
	read_and_stash(fd, &stash, &readed);
	return (line);
}
