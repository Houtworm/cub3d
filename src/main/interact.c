/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   interact.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 16:50:23 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/09 00:57:58 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_getstepxinteract(t_varlist *vl, int mapx)
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

int	ft_getstepyinteract(t_varlist *vl, int mapy)
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

int	ft_prepinteract(t_varlist *vl, int x)
{
	double	camerax;

	camerax = 2 * x / (double)vl->w - 1;
	vl->raydirx = vl->dirx + vl->planex * camerax;
	vl->raydiry = vl->diry + vl->planey * camerax;
	vl->deltadistx = fabs(1 / vl->raydirx);
	vl->deltadisty = fabs(1 / vl->raydiry);
	return (0);
}

void	ft_interact(t_varlist *vl)
{
	int		stepx;
	int		stepy;
	int		mapx;
	int		mapy;

	mapx = (int)vl->posx;
	mapy = (int)vl->posy;
	ft_prepinteract(vl, vl->w / 2);
	stepx = ft_getstepxinteract(vl, mapx);
	stepy = ft_getstepyinteract(vl, mapy);
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
	if (vl->map[mapx][mapy] == '4')
		ft_finish(vl);
}
