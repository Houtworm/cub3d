/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_doors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:29:46 by fsarkoh           #+#    #+#             */
/*   Updated: 2024/03/14 18:14:14 by djonker          ###   ########.fr       */
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

	doors = (t_door **)ft_calloc((n_doors(vl) + 1), sizeof(t_door *));
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
	return (doors);
}
