/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 16:48:55 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/10 09:31:08 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

t_varlist	ft_parseconfigfile(t_varlist vl, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_errorexit("file does not exist", "parseconfigfile", 1);
	while (get_next_line(fd, &line))
	{
		ft_checkline(&vl, line);
		if (vl.walltxt[0] && vl.walltxt[1] && vl.walltxt[2] && vl.walltxt[3])
		{
			if (vl.ccolor && vl.fcolor)
			{
				vl.map = ft_getmap(&vl, fd);
				break ;
			}
		}
		free(line);
	}
	close(fd);
	free(line);
	return (vl);
}
