/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:50:23 by houtworm          #+#    #+#             */
/*   Updated: 2024/03/13 15:01:23 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_checkmove(t_varlist *vl, double movy, double movx, double movespeed)
{
	double	length;
	double	newx;
	double	newy;

	length = sqrt(movx * movx + movy * movy);
	if (length != 0)
	{
		movx /= length;
		movy /= length;
	}
	newx = vl->posx + movx * movespeed * vl->run;
	newy = vl->posy + movy * movespeed * vl->run;
	if (vl->map[(int)newx][(int)vl->posy] == '0' \
		|| vl->map[(int)newx][(int)vl->posy] == 'd')
		vl->posx = newx;
	if (vl->map[(int)vl->posx][(int)newy] == '0' \
		|| vl->map[(int)vl->posx][(int)newy] == 'd')
		vl->posy = newy;
}

void	ft_processmove(t_varlist *vl, double movspd, double movx, double movy)
{
	if (mlx_is_key_down(vl->mlx, MLX_KEY_W))
	{
		movx += vl->dirx;
		movy += vl->diry;
	}
	if (mlx_is_key_down(vl->mlx, MLX_KEY_A))
	{
		movx -= vl->diry;
		movy += vl->dirx;
	}
	if (mlx_is_key_down(vl->mlx, MLX_KEY_S))
	{
		movx -= vl->dirx;
		movy -= vl->diry;
	}
	if (mlx_is_key_down(vl->mlx, MLX_KEY_D))
	{
		movx += vl->diry;
		movy -= vl->dirx;
	}
	ft_checkmove(vl, movy, movx, movspd);
}
