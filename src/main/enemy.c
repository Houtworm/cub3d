/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enemy.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 14:13:07 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/09 20:52:04 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_animateenemies(t_varlist *vl)
{
	int	i;

	i = 0;
	while (vl->spritecount > i)
	{
		if (vl->sprite[i].status && vl->sprite[i].type == 3)
		{
			if (vl->sprite[i].status == 0)
			{
				vl->sprite[i].x = vl->sprite[i].x + 0.01;
				vl->sprite[i].y = vl->sprite[i].y + 0.01;
			}
			if (vl->sprite[i].status == 1)
			{
				if (vl->tottime - vl->sprite[i].anitime > 0.8)
				{
					vl->sprite[i].anitime = vl->tottime;
					vl->sprite[i].number++;
					if (vl->sprite[i].number == 4)
						vl->sprite[i].number = 2;
					else if (vl->sprite[i].number == 3)
						vl->hp = vl->hp - 10;
				}
			}
			if (vl->sprite[i].status == 2)
			{
				if (vl->tottime - vl->sprite[i].anitime > 0.2 && vl->sprite[i].number < 4)
				{
					vl->sprite[i].anitime = vl->tottime;
					vl->sprite[i].number++;
				}
			}
		}
		i++;
	}
}
