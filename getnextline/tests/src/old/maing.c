/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   maing.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 18:53:24 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/26 18:53:25 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/get_next_line.h"
#include <stdio.h>

int	printline(int fd, char *line)
{
	int	r;

	r = get_next_line(fd, &line);
	printf("<<%d>>%s\n", r, line);
	free(line);
	return (r);
}

int	main(void)
{
	int		fd[6];
	int		r[5];
	char	*line;

	fd[5] = 5;
	while (--fd[5] >= 0)
		r[fd[5]] = 2;
	fd[0] = open("tests/files/new/compare1", O_RDONLY);
	fd[1] = open("tests/files/new/basic", O_RDONLY);
	fd[2] = open("tests/files/new/extreme1", O_RDONLY);
	fd[3] = open("tests/files/new/compare2", O_RDONLY);
	fd[4] = open("tests/files/new/extreme2", O_RDONLY);
	while (r[0] > 0 || r[1] > 0 || r[2] > 0 || r[3] > 0 || r[4] > 0)
	{
		fd[5] = 0;
		while (fd[5] < 5)
		{
			if (r[fd[5]] > 0)
				r[fd[5]] = printline(fd[fd[5]], line);
			fd[5]++;
		}
	}
	return (0);
}
