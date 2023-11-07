/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pickup.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 14:13:07 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/07 06:40:46 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_pickup(t_varlist *vl, int i)
{
	if (vl->sprite[i].number < 4)
		vl->treasure++;
	else if (vl->sprite[i].number == 4)
		vl->hp = vl->hp + 30;
	else if (vl->sprite[i].number == 5)
		vl->hp = vl->hp + 20;
	else if (vl->sprite[i].number == 6)
		vl->hp = vl->hp + 10;
	else if (vl->sprite[i].number == 7)
		ft_putendl("Found gold key\n");
	else if (vl->sprite[i].number == 8)
		ft_putendl("Found blue key\n");
	else if (vl->sprite[i].number == 9)
		vl->mgun = 1;
	else if (vl->sprite[i].number == 10)
		vl->ggun = 1;
	else if (vl->sprite[i].number == 11)
		vl->ammo += 10;
	while (vl->sprite[i].x)
	{
		vl->sprite[i] = vl->sprite[i + 1];
		i++;
	}
	vl->spritecount--;
}

void	ft_checkpickup(t_varlist *vl)
{
	int	i;

	i = 0;
	while (vl->sprite[i].x)
	{
		if (vl->sprite[i].type == 2)
		{
			if ((int)vl->sprite[i].x == (int)vl->posx)
			{
				if ((int)vl->sprite[i].y == (int)vl->posy)
				{
					ft_pickup(vl, i);
				}
			}
		}
		i++;
	}
}
