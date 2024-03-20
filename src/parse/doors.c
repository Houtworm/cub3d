/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:    :+:            */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:24:50 by fsarkoh           #+#    #+#             */
/*   Updated: 2024/03/20 02:09:07 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

t_door	*ft_get_door(t_varlist *vl, int x, int y)
{
	unsigned int	i;

	i = 0;
	while (vl->doors[i])
	{
		if (vl->doors[i]->x == x && vl->doors[i]->y == y)
			return (vl->doors[i]);
		i++;
	}
	return (NULL);
}

static void	ft_move_door(t_varlist *vl, t_door *door)
{
	if (door->status == DOOR_CLOSING)
	{
		if (!((int)vl->posx == door->x && (int)vl->posy == door->y))
			door->closedness += DOOR_SPEED;
	}
	else if (door->status == DOOR_OPENING)
		door->closedness -= DOOR_SPEED;
}

static void	ft_update_door_state(t_varlist *vl, t_door *door)
{
	if (door->closedness >= 1)
	{
		door->closedness = 1;
		door->status = DOOR_IDLE;
		vl->map[door->x][door->y] = 'D';
	}
	else if (door->closedness <= 0)
	{
		if (door->status == DOOR_OPENING)
			door->time = 0;
		else
			door->time += vl->frametime;
		door->closedness = 0;
		door->status = DOOR_IDLE;
		vl->map[door->x][door->y] = 'd';
		if (door->time >= DOOR_TILL_CLOSE)
			door->status = DOOR_CLOSING;
	}
}

void	ft_update_doors(t_varlist *vl)
{
	t_door			*door;
	unsigned int	i;

	i = 0;
	while (vl->doors[i])
	{
		door = vl->doors[i];
		ft_move_door(vl, door);
		ft_update_door_state(vl, door);
		i++;
	}
}
