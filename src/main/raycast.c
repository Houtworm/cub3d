/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:36:42 by djonker           #+#    #+#             */
/*   Updated: 2024/03/13 15:25:16 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_prepcast(t_varlist *vl, int x)
{
	double	camerax;

	camerax = 2 * x / (double)vl->w - 1;
	vl->raydirx = vl->dirx + vl->planex * camerax;
	vl->raydiry = vl->diry + vl->planey * camerax;
	vl->deltadistx = fabs(1 / vl->raydirx);
	vl->deltadisty = fabs(1 / vl->raydiry);
	return (0);
}

static void	ft_updateray(t_varlist *vl, int stepx, int stepy)
{
	if (vl->sidedistx < vl->sidedisty)
	{
		vl->sidedistx += vl->deltadistx;
		vl->mapx += stepx;
		vl->side = 0;
	}
	else
	{
		vl->sidedisty += vl->deltadisty;
		vl->mapy += stepy;
		vl->side = 1;
	}
}

static int	ft_hitdoor(t_varlist *vl)
{
	t_door	*door;
	double	wallx;

	door = ft_get_door(vl, vl->mapx, vl->mapy);
	if (!vl->side)
	{
		wallx = vl->posy + vl->raydiry * (vl->sidedistx - vl->deltadistx);
		wallx -= floor(wallx);
		if (vl->raydirx > 0)
			wallx = 1 - wallx;
		if (wallx >= (1 - door->closedness))
			return (1);
	}
	else
	{
		wallx = vl->posx + vl->raydirx * (vl->sidedisty - vl->deltadisty);
		wallx -= floor(wallx);
		if (vl->raydiry < 0)
			wallx = 1 - wallx;
		if (wallx >= (1 - door->closedness))
			return (1);
	}
	return (0);
}

void	ft_raycast(t_varlist *vl, int x)
{
	int		hit;
	int		stepx;
	int		stepy;

	hit = ft_prepcast(vl, x);
	stepx = ft_getstepx(vl, vl->mapx);
	stepy = ft_getstepy(vl, vl->mapy);
	while (hit == 0)
	{
		ft_updateray(vl, stepx, stepy);
		if (vl->map[vl->mapx][vl->mapy] == 'D' || \
			vl->map[vl->mapx][vl->mapy] == 'd')
			hit = ft_hitdoor(vl);
		if (vl->map[vl->mapx][vl->mapy] == '1' || \
			vl->map[vl->mapx][vl->mapy] == '4')
			hit = 1;
	}
}
