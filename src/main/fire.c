/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   weapon.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 14:13:07 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/07 22:25:56 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_fireweapon(t_varlist *vl)
{
	if (vl->reload)
	{
		if (vl->tottime - vl->firetime > vl->reloadtime)
		{
			vl->firetime = vl->tottime;
			vl->reload++;
			if (vl->reload == 2)
			{
				if (vl->weapon)
					vl->ammo--;
				ft_firebullet(vl);
			}
			if (vl->reload > 4)
				vl->reload = 0;
		}
	}

}
