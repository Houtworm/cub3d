/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 17:33:50 by houtworm      #+#    #+#                 */
/*   Updated: 2024/03/14 18:46:58 by djonker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_getmapx(t_varlist *vl, char **map, int y, int fd)
{
	int		ret;
	int		x;
	char	*line;

	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (line[0])
			break ;
		free(line);
	}
	x = 0;
	while (ret && x <= 1024 && line[x])
	{
		if (x > 1000)
			ft_errorexit("The map is too big, 1000x1000 max\n", "", 1);
		map[y][x] = ft_checkmapelement(vl, line[x], x, y);
		if (x > vl->mapsizex)
			vl->mapsizex = x;
		x++;
	}
	if (ret)
		free(line);
	return (ret);
}

char	**ft_getmap(t_varlist *vl, int fd)
{
	int		y;
	int		ret;
	char	**map;

	vl->mapsizex = 0;
	vl->mapsizey = 0;
	map = ft_calloc(1024, 8);
	y = 0;
	ret = 1;
	while (y <= 1024 && ret > 0)
	{
		if (y > 1000)
			ft_errorexit("The map is too big, 1000x1000 max\n", "", 1);
		map[y] = ft_calloc(1024, 8);
		ret = ft_getmapx(vl, map, y, fd);
		if (ret == 0)
			return (map);
		vl->mapsizey = y;
		y++;
	}
	ft_errorexit("Something went wrong", "ft_getmap", 1);
	return (0);
}
