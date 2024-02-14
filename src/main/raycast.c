/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:    :+:            */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:36:42 by djonker           #+#    #+#             */
/*   Updated: 2024/02/14 17:19:56 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int ft_getstepx(t_varlist *vl, int mapx)
{
	int stepx;

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

int ft_getstepy(t_varlist *vl, int mapy)
{
	int stepy;

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

int ft_prepcast(t_varlist *vl, int x)
{
	double camerax;

	camerax = 2 * x / (double)vl->w - 1;
	vl->raydirx = vl->dirx + vl->planex * camerax;
	vl->raydiry = vl->diry + vl->planey * camerax;
	vl->deltadistx = fabs(1 / vl->raydirx);
	vl->deltadisty = fabs(1 / vl->raydiry);
	return (0);
}

// if ft_checkhalf returns 0.5 or higher it means the cell was hit through the middle in other words it hit the door. 
int	ft_checkhalf(t_varlist *vl)
{	
	double	p0;
	double	p1;

	if (!vl->side)
	{
//		p0 is the position of the rayhit on the x-axis.
//		p1 is the position of the rayhit on the y-axis if there was no door obstructing it.
		p0 = vl->raydiry * vl->sidedistx;
		p1 = vl->raydiry * (vl->sidedisty + vl->deltadisty);
	}
	else
	{
//		p0 is the position of the rayhit on the y-axis.
//		p1 is the position of the rayhit on the x-axis if there was no door obstructing it.
		p0 = vl->raydirx * vl->sidedisty;
		p1 = vl->raydirx * (vl->sidedistx + vl->deltadistx);
	}
//	returns the difference
	return (fabs(p0 - p1));
	/*return (p0 - p1);*/
}

void ft_raycast(t_varlist *vl, int x)
{
	int hit;
	int stepx;
	int stepy;
	double	half;

	hit = ft_prepcast(vl, x);
	stepx = ft_getstepx(vl, vl->mapx);
	stepy = ft_getstepy(vl, vl->mapy);
	/*if (x == vl->w/2)*/
		/*printf("dir: (%f, %f)\n", vl->dirx, vl->diry);*/
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
			half = ft_checkhalf(vl);
			if (half > 0.5)
			{
				if (!vl->side)
					vl->sidedistx += vl->deltadistx * 0.5;
				else
					vl->sidedisty += vl->deltadisty * 0.5;
				hit = 1;
			}
		}
		if (vl->map[vl->mapx][vl->mapy] == '1' ||
			vl->map[vl->mapx][vl->mapy] == '4')
			hit = 1; 
	}
}
