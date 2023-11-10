/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fire.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 14:13:07 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/10 06:01:44 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_killnazi(t_varlist *vl, int mapx, int mapy)
{
	int	i;

	i = 0;
	while (vl->spritecount > i)
	{
		if (mapy == (int)vl->sprite[i].y && mapx == (int)vl->sprite[i].x)
		{
			if (vl->map[mapx][mapy] == '3')
			{
				vl->sprite[i].status = 2;
				vl->sprite[i].anitime = vl->tottime;
				vl->kills++;
			}
			if (vl->map[mapx][mapy] == '2')
				vl->sprite[i].status = 1;
			vl->map[mapx][mapy] = '0';
			return ;
		}
		i++;
	}
}

int	ft_checkifhit(t_varlist *vl, int mapx, int mapy)
{
	if (vl->map[mapx][mapy] == '3' || vl->map[mapx][mapy] == '2')
	{
		ft_killnazi(vl, mapx, mapy);
		return (1);
	}
	if (vl->map[mapx][mapy] == '1' || vl->map[mapx][mapy] == '4')
		return (1);
	if (vl->weapon == 0)
		return (1);
	return (0);
}

int	ft_travelstep(t_varlist *vl, int map, int step, int xy)
{
	if (xy == 1)
	{
		vl->sidedistx += vl->deltadistx;
		map += step;
		vl->side = 0;
	}
	else
	{
		vl->sidedisty += vl->deltadisty;
		map += step;
		vl->side = 1;
	}
	return (map);
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
	hit = ft_prepcast(vl, vl->w / 2);
	stepx = ft_getstepx(vl, mapx);
	stepy = ft_getstepy(vl, mapy);
	while (!hit)
	{
		if (vl->sidedistx < vl->sidedisty)
			mapx = ft_travelstep(vl, mapx, stepx, 1);
		else
			mapy = ft_travelstep(vl, mapy, stepy, 2);
		hit = ft_checkifhit(vl, mapx, mapy);
	}
}

void	ft_fireweapon(t_varlist *vl)
{
	if (vl->reload)
	{
		if (vl->tottime - vl->firetime > vl->reloadtime)
		{
			vl->firetime = vl->tottime;
			vl->reload++;
			if (vl->reload == 2)
			{
				if (vl->weapon)
					vl->ammo--;
				ft_firebullet(vl);
			}
			if (vl->reload > 4)
				vl->reload = 0;
		}
	}
}
