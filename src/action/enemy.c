/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enemy.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 14:13:07 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/10 07:09:43 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_checkhealth(t_varlist *vl)
{
	if (vl->hp <= 0)
		ft_youdied(vl);
}

void	ft_dieanimation(t_varlist *vl, int i)
{
	if (vl->tottime - vl->sprite[i].anitime > 0.2 && vl->sprite[i].number < 4)
	{
		vl->sprite[i].anitime = vl->tottime;
		vl->sprite[i].number++;
	}
}

void	ft_fireanimation(t_varlist *vl, int i)
{
	if (vl->tottime - vl->sprite[i].anitime > 0.8)
	{
		vl->sprite[i].anitime = vl->tottime;
		vl->sprite[i].number++;
		if (vl->sprite[i].number == 4)
			vl->sprite[i].number = 2;
		else if (vl->sprite[i].number == 3)
		{
			vl->hp = vl->hp - 10;
			vl->flash = 6;
			vl->flashcolor = 1;
		}
	}
}

void	ft_enemyaction(t_varlist *vl)
{
	int	i;

	i = 0;
	while (vl->spritecount > i)
	{
		if (vl->sprite[i].status && vl->sprite[i].type == 3)
		{
			if (vl->sprite[i].status == 1)
				ft_fireanimation(vl, i);
			if (vl->sprite[i].status == 2)
				ft_dieanimation(vl, i);
		}
		i++;
	}
}
