/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:24:50 by fsarkoh           #+#    #+#             */
/*   Updated: 2024/03/07 19:10:00 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static unsigned int	n_doors(t_varlist *vl)
{
	unsigned int	n;
	int				x;
	int				y;

	n = 0;
	x = 0;
	while (x <= vl->mapsizey)
	{
		y = 0;
		while (y <= vl->mapsizex)
		{
			if (vl->map[x][y] == 'D')
				n++;
			y++;
		}
		x++;
	}
	return (n);
}

static t_door	*init_door(int x, int y)
{
	t_door	*door;

	door = (t_door *)malloc(sizeof(t_door));
	if (!door)
		return (NULL);
	door->x = x;
	door->y = y;
	door->closedness = 1;
	door->status = DOOR_IDLE;
	return (door);
}

t_door	**ft_initdoors(t_varlist *vl)
{
	t_door			**doors;
	unsigned int	i;
	int				x;
	int				y;

	doors = (t_door **)malloc((n_doors(vl) + 1) * sizeof(t_door *));
	if (!doors)
		return (NULL);
	i = 0;
	x = 0;
	while (x <= vl->mapsizey)
	{
		y = 0;
		while (y <= vl->mapsizex)
		{
			if (vl->map[x][y] == 'D')
			{
				doors[i] = init_door(x, y);
				i++;
			}
			y++;
		}
		x++;
	}
	doors[i] = NULL;
	return (doors);
}

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

void	ft_update_doors(t_varlist *vl)
{
	t_door			*door;
	unsigned int	i;

	i = 0;
	while (vl->doors[i])
	{
		door = vl->doors[i];
		if (door->status == DOOR_CLOSING)
		{
			if (!((int)vl->posx == door->x && (int)vl->posy == door->y))
				door->closedness += DOOR_SPEED;
		}
		else if (door->status == DOOR_OPENING)
			door->closedness -= DOOR_SPEED;
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
		i++;
	}
}
