/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:36:42 by djonker           #+#    #+#             */
/*   Updated: 2023/11/20 18:49:53 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_getstepx(t_varlist *vl, int mapx)
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

int	ft_getstepy(t_varlist *vl, int mapy)
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
		if (vl->map[vl->mapx][vl->mapy] == 'D')
		{
			if (vl->side)
				vl->sidedisty += vl->deltadisty / 2;
			else
				vl->sidedistx += vl->deltadistx / 2;
			hit = 1;
		}
		if (vl->map[vl->mapx][vl->mapy] == '1' || \
				vl->map[vl->mapx][vl->mapy] == '4')
			hit = 1;
	}
}
