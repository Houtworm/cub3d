/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:    :+:            */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:48:55 by houtworm          #+#    #+#             */
/*   Updated: 2024/03/20 04:08:35 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_checkmapexists(t_varlist vl)
{
	if (!vl.walltxt[0] || !vl.walltxt[1] || !vl.walltxt[2] \
			|| !vl.walltxt[3] || !vl.ccolor || !vl.fcolor)
		ft_errorexit("Missing parameter in .cub file ", "checkmapexists", 1);
	if (!vl.mapsizex || !vl.mapsizey)
		ft_errorexit("map is missing ", "checkmapexists", 1);
}

int	ft_checkfilename(char *filename)
{
	int	i;

	i = ft_strlen(filename);
	if (i < 5 || \
			filename[i - 1] != 'b' || \
			filename[i - 2] != 'u' || \
			filename[i - 3] != 'c' || \
			filename[i - 4] != '.')
		return (1);
	return (0);
}

t_varlist	ft_parseconfigfile(t_varlist vl, char *filename)
{
	int		fd;
	char	*line;

	if (ft_checkfilename(filename))
		ft_errorexit("Bad filename", " ft_parseconfigfile", 1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_errorexit("file does not exist ", "parseconfigfile", 1);
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
	ft_checkmapexists(vl);
	return (vl);
}
