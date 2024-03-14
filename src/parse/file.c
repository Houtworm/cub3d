/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:48:55 by houtworm          #+#    #+#             */
/*   Updated: 2024/03/14 17:24:32 by djonker          ###   ########.fr       */
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
		if (vl.walltxt[0] && vl.walltxt[1] && vl.walltxt[2] && vl.walltxt[3] \
			&& vl.ccolor && vl.fcolor)
		{
			vl.map = ft_getmap(&vl, fd);
			vl.doors = ft_initdoors(&vl);
			break ;
		}
		free(line);
	}
	close(fd);
	free(line);
	if (!vl.walltxt[0] || !vl.walltxt[1] || !vl.walltxt[2] \
			|| !vl.walltxt[3] || !vl.ccolor || !vl.fcolor)
		ft_errorexit("Missing parameter in .cub file", "parseconfigfile", 1);
	return (vl);
}
