/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:43:46 by juhanse           #+#    #+#             */
/*   Updated: 2024/11/27 14:30:24 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	char	*a;
	char	*empty;
	char	*b;

	fd = open("test.txt", O_RDONLY);
	a = get_next_line(fd);
	empty = get_next_line(fd);
	b = get_next_line(fd);
	if (!a || !empty || !b)
		return (0);
	printf("%s%s%s", a, empty, b);
/* 	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	} */
	return (0);
}
