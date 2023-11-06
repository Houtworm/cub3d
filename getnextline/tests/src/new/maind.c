/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   maind.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 18:52:53 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/26 18:52:54 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*line1;
	char	*line2;

	line1 = "\n";
	line2 = "\n";
	fd1 = open("tests/files/new/compare1", O_RDONLY);
	fd2 = open("tests/files/new/compare2", O_RDONLY);
	while (line1 || line2)
	{
		if (line1)
		{
			line1 = get_next_line(fd1);
			printf("%s\n", line1);
			free(line1);
		}
		if (line2)
		{
			line2 = get_next_line(fd2);
			printf("%s\n", line2);
			free(line2);
		}
	}
	return (0);
}
