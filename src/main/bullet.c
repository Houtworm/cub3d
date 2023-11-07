/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bullet.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 14:13:07 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/07 06:10:09 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_getstepxbullet(t_varlist *vl, int mapx)
{
	int	stepx;

	if (vl->raydirx < 0)
	{
		stepx = -1;
		vl->sidedistx = (vl->posx - mapx) * vl->deltadistx;
	}
	else
	{
		stepx = 1;
		vl->sidedistx = (mapx + 1.0 - vl->posx) * vl->deltadistx;
	}
	return (stepx);
}

int	ft_getstepybullet(t_varlist *vl, int mapy)
{
	int	stepy;

	if (vl->raydiry < 0)
	{
		stepy = -1;
		vl->sidedisty = (vl->posy - mapy) * vl->deltadisty;
	}
	else
	{
		stepy = 1;
		vl->sidedisty = (mapy + 1.0 - vl->posy) * vl->deltadisty;
	}
	return (stepy);
}

int	ft_prepbullet(t_varlist *vl, int x)
{
	double	camerax;

	camerax = 2 * x / (double)vl->w - 1;
	vl->raydirx = vl->dirx + vl->planex * camerax;
	vl->raydiry = vl->diry + vl->planey * camerax;
	vl->deltadistx = fabs(1 / vl->raydirx);
	vl->deltadisty = fabs(1 / vl->raydiry);
	return (0);
}

void	ft_killnazi(t_varlist *vl, int mapx, int mapy)
{
	int	i;

	i = 0;
	vl->map[mapx][mapy] = '0';
	while (vl->spritecount > i)
	{
		if (mapy == (int)vl->sprite[i].y && mapx == (int)vl->sprite[i].x)
		{
			vl->sprite[i].status = 2;
			vl->sprite[i].anitime = vl->tottime;
			vl->kills++;
			return ;
		}
		i++;
	}
}

void	ft_firebullet(t_varlist *vl)
{
	int		hit;
	int		stepx;
	int		stepy;
	int		mapx;
	int		mapy;

	mapx = (int)vl->posx;
	mapy = (int)vl->posy;
	hit = ft_prepbullet(vl, vl->w / 2);
	stepx = ft_getstepxbullet(vl, mapx);
	stepy = ft_getstepybullet(vl, mapy);
	while (hit == 0)
	{
		if (vl->sidedistx < vl->sidedisty)
		{
			vl->sidedistx += vl->deltadistx;
			mapx += stepx;
			vl->side = 0;
		}
		else
		{
			vl->sidedisty += vl->deltadisty;
			mapy += stepy;
			vl->side = 1;
		}
		if (vl->map[mapx][mapy] == '3')
		{
			ft_killnazi(vl, mapx, mapy);
			return ;
		}
		if (vl->map[mapx][mapy] == '1')
			return ;
	}
}
