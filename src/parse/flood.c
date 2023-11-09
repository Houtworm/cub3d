/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flood.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 14:13:07 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/09 07:44:39 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_flood(t_varlist vl, char **fillmap, int x, int y)
{
	if (y == 0)
		return (1);
	if (fillmap[y - 1][x] != '1')
	{
		fillmap[y - 1][x] = '1';
		if (ft_flood(vl, fillmap, x, y - 1))
			return (1);
	}
	if (y > vl.mapsizey)
		return (1);
	if (fillmap[y + 1][x] != '1')
	{
		fillmap[y + 1][x] = '1';
		if (ft_flood(vl, fillmap, x, y + 1))
			return (1);
	}
	if (x == 0)
		return (1);
	if (fillmap[y][x - 1] != '1')
	{
		fillmap[y][x - 1] = '1';
		if (ft_flood(vl, fillmap, x - 1, y))
			return (1);
	}
	if (x > vl.mapsizex)
		return (1);
	if (fillmap[y][x + 1] != '1')
	{
		fillmap[y][x + 1] = '1';
		if (ft_flood(vl, fillmap, x + 1, y))
			return (1);
	}
	return (0);
}

int	ft_floodfill(t_varlist vl)
{
	int		y;
	int		x;
	char	**fillmap;

	fillmap = ft_calloc(1024, 8);
	y = 0;
	while (vl.map[y])
	{
		fillmap[y] = ft_strdup(vl.map[y]);
		y++;
	}
	y = (int)vl.posy;
	x = (int)vl.posx;
	fillmap[y][x] = '1';
	x = ft_flood(vl, fillmap, x, y);
	ft_frearr(fillmap);
	return (x);
}
