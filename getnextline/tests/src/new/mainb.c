/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mainb.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 18:52:48 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/26 18:52:48 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd1;
	char	*line;

	line = "\n";
	fd1 = open("tests/files/new/extreme1", O_RDONLY);
	while (line)
	{
		line = get_next_line(fd1);
		printf("%s\n", line);
		free(line);
	}
	return (0);
}
