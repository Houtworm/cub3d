/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   acro.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 16:50:23 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/10 05:16:39 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_processacro(t_varlist *vl, double movespeed)
{
	if (mlx_is_key_down(vl->mlx, MLX_KEY_SPACE))
	{
		if (vl->menu)
			vl->menu = 3;
		if (vl->jump < 10)
			vl->jump = 200;
	}
	else if (vl->jump > 0)
		vl->jump = vl->jump - 150 * movespeed;
	if (mlx_is_key_down(vl->mlx, MLX_KEY_LEFT_CONTROL))
		vl->jump = -200;
	else if (vl->jump < 0)
		vl->jump = vl->jump + 150 * movespeed;
	if (mlx_is_key_down(vl->mlx, MLX_KEY_LEFT_SHIFT))
		vl->run = 2;
	else
		vl->run = 1;
}
