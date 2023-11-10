/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   interact.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 16:50:23 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/10 05:30:51 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_interact(t_varlist *vl)
{
	int		stepx;
	int		stepy;
	int		mapx;
	int		mapy;

	mapx = (int)vl->posx;
	mapy = (int)vl->posy;
	ft_prepcast(vl, vl->w / 2);
	stepx = ft_getstepx(vl, mapx);
	stepy = ft_getstepy(vl, mapy);
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
