/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   maing.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 18:53:02 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/26 18:53:02 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/get_next_line.h"
#include <stdio.h>

char	*printline(char *line, int fd)
{
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
}

int	main(void)
{
	int		*fd[6];
	char	*line[5];

	fd[5] = 5;
	while (--fd[5] >= 0)
		*line[fd5] = "\n";
	fd[0] = open("tests/files/new/compare1", O_RDONLY);
	fd[1] = open("tests/files/new/basic", O_RDONLY);
	fd[2] = open("tests/files/new/extreme1", O_RDONLY);
	fd[3] = open("tests/files/new/compare2", O_RDONLY);
	fd[4] = open("tests/files/new/extreme2", O_RDONLY);
	while (line[0] || line[1] || line[2] || line[3] || line[4])
	{
		if (line[0])
			line[0] = printline(line[0], fd[0]);
		if (line[1])
			line[1] = printline(line[1], fd[1]);
		if (line[2])
			line[2] = printline(line[2], fd[2]);
		if (line[3])
			line[3] = printline(line[3], fd[3]);
		if (line[4])
			line[4] = printline(line[4], fd[4]);
	}
	return (0);
}
