/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:50:23 by houtworm          #+#    #+#             */
/*   Updated: 2024/03/01 15:14:44 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	ft_interact_door(t_varlist *vl, int mapx, int mapy)
{
	t_door	*door;

	door = ft_get_door(vl, mapx, mapy);
	if (door->status == DOOR_IDLE)
	{
		if (door->closedness == 1)
			door->status = DOOR_OPENING;
		else
			door->status = DOOR_CLOSING;
	}
}

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
	if (vl->map[mapx][mapy] == 'D')
		ft_interact_door(vl, mapx, mapy);
	else if (vl->map[mapx][mapy] == 'd')
		ft_interact_door(vl, mapx, mapy);
}
