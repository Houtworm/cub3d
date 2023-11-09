/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 17:33:50 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/09 23:38:43 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	ft_setplayerpos(t_varlist *vl, char dir, int x, int y)
{
	vl->posx = x + 0.5;
	vl->posy = y + 0.5;
	if (dir == 'N')
	{
		vl->dirx = -1;
		vl->diry = 0;
		vl->planex = 0;
		vl->planey = 0.66;
	}
	else if (dir == 'E')
	{
		vl->dirx = 0;
		vl->diry = 1;
		vl->planex = 0.66;
		vl->planey = 0;
	}
	else if (dir == 'S')
	{
		vl->dirx = 1;
		vl->diry = 0;
		vl->planex = 0;
		vl->planey = -0.66;
	}
	else if (dir == 'W')
	{
		vl->dirx = 0;
		vl->diry = -1;
		vl->planex = -0.66;
		vl->planey = 0;
	}
	return ('0');
}

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
			if (ft_strchr(" 0", line[x]))
				map[y][x] = '0';
			else if (line[x] == '1')
				map[y][x] = '1';
			else if (ft_strchr("NESW", line[x]))
				map[y][x] = ft_setplayerpos(vl, line[x], y, x);
			else if (line[x] == 'D')
				map[y][x] = '0';
			else if (line[x] == 'B')
				map[y][x] = ft_addsoliddecor(vl, y, x, 0);
			else if (line[x] == 'b')
				map[y][x] = ft_addsoliddecor(vl, y, x, 1);
			else if (line[x] == 'L')
				map[y][x] = ft_addsoliddecor(vl, y, x, 2);
			else if (line[x] == 'A')
				map[y][x] = ft_addsoliddecor(vl, y, x, 3);
			else if (line[x] == 'P')
				map[y][x] = ft_addsoliddecor(vl, y, x, 4);
			else if (line[x] == 'p')
				map[y][x] = ft_addsoliddecor(vl, y, x, 5);
			else if (line[x] == 'V')
				map[y][x] = ft_addsoliddecor(vl, y, x, 6);
			else if (line[x] == 'f')
				map[y][x] = ft_addsoliddecor(vl, y, x, 7);
			else if (line[x] == 'T')
				map[y][x] = ft_addsoliddecor(vl, y, x, 8);
			else if (line[x] == 's')
				map[y][x] = ft_addsoliddecor(vl, y, x, 9);
			else if (line[x] == 'l')
				map[y][x] = ft_addwalktroughdecor(vl, y, x, 10);
			else if (line[x] == 'C')
				map[y][x] = ft_addwalktroughdecor(vl, y, x, 11);
			else if (line[x] == '$')
				map[y][x] = ft_addpickup(vl, y, x, 0);
			else if (line[x] == '#')
				map[y][x] = ft_addpickup(vl, y, x, 1);
			else if (line[x] == '*')
				map[y][x] = ft_addpickup(vl, y, x, 2);
			else if (line[x] == '&')
				map[y][x] = ft_addpickup(vl, y, x, 3);
			else if (line[x] == '9')
				map[y][x] = ft_addpickup(vl, y, x, 4);
			else if (line[x] == '8')
				map[y][x] = ft_addpickup(vl, y, x, 5);
			else if (line[x] == '7')
				map[y][x] = ft_addpickup(vl, y, x, 6);
			else if (line[x] == '[')
				map[y][x] = ft_addpickup(vl, y, x, 7);
			else if (line[x] == ']')
				map[y][x] = ft_addpickup(vl, y, x, 8);
			else if (line[x] == '3')
				map[y][x] = ft_addpickup(vl, y, x, 9);
			else if (line[x] == '4')
				map[y][x] = ft_addpickup(vl, y, x, 10);
			else if (line[x] == '2')
				map[y][x] = ft_addpickup(vl, y, x, 11);
			else if (line[x] == 'K')
				map[y][x] = ft_addenemy(vl, y, x, 0);
			else if (line[x] == 'X')
				map[y][x] = '4';
			else
				ft_errorexit("Invalid character on the map", "", 1);
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
