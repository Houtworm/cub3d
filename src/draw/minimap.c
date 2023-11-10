/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 14:13:07 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/10 11:09:51 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_drawvertlinemap(t_varlist *vl, int y, int mapy)
{
	int	mapx;
	int	x;

	x = 0;
	mapx = (int)vl->posy - 10;
	while (x <= 21)
	{
		if (x == 10 && y == 10)
			mlx_put_pixel(vl->mimg, x, y, 0xFFFF00FF);
		else if (mapy < 0 || mapx < 0)
			mlx_put_pixel(vl->mimg, x, y, 0xFFFFFF00);
		else if (vl->mapsizey < mapy || vl->mapsizex < mapx)
			mlx_put_pixel(vl->mimg, x, y, 0xFFFFFF00);
		else if (vl->map[mapy][mapx] == '0')
			mlx_put_pixel(vl->mimg, x, y, 0x646464FF);
		else if (vl->map[mapy][mapx] == '1')
			mlx_put_pixel(vl->mimg, x, y, 0x0000FFFF);
		else if (vl->map[mapy][mapx] == '2')
			mlx_put_pixel(vl->mimg, x, y, 0x00FF00FF);
		else if (vl->map[mapy][mapx] == '3')
			mlx_put_pixel(vl->mimg, x, y, 0xFF0000FF);
		mapx++;
		x++;
	}
}

void	ft_drawminimap(t_varlist *vl)
{
	int	mapy;
	int	y;

	if (vl->minimap % 2)
	{
		mapy = (int)vl->posx - 10;
		y = 0;
		while (y <= 21)
		{
			ft_drawvertlinemap(vl, y, mapy);
			mapy++;
			y++;
		}
		mlx_resize_image(vl->mimg, 168, 168);
		mlx_image_to_window(vl->mlx, vl->mimg, vl->w - 178, 10);
		mlx_set_instance_depth(vl->mimg->instances, 11);
	}
}
