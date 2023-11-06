/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mainf.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 18:52:59 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/26 18:52:59 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd1;
	char	*line;

	line = "\n";
	fd1 = 0;
	while (line)
	{
		line = get_next_line(fd1);
		printf("%s\n", line);
		free(line);
	}
	return (0);
}
