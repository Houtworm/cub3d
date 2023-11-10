/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 17:33:50 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/10 08:49:21 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	**ft_getmap(t_varlist *vl, int fd)
{
	int		y;
	int		x;
	int		ret;
	char	**map;
	char	*line;

	map = ft_calloc(1024, 8);
	y = 0;
	x = 0;
	ret = 1;
	while (y <= 1024 && ret > 0)
	{
		if (y > 1000)
			return (NULL);
		map[y] = ft_calloc(1024, 8);
		while (ret > 0)
		{
			ret = get_next_line(fd, &line);
			if (line[0])
				break ;
			free(line);
		}
		if (ret == 0)
			return (map);
		x = 0;
		while (x <= 1024 && line[x])
		{
			if (x > 1000)
				return (NULL);
			map[y][x] = ft_checkmapelement(vl, line[x], x, y);
			if (x > vl->mapsizex)
				vl->mapsizex = x;
			x++;
		}
		free(line);
		if (y > vl->mapsizey)
			vl->mapsizey = y;
		y++;
	}
	ft_errorexit("Something went wrong", "ft_getmap", 1);
	return (0);
}
