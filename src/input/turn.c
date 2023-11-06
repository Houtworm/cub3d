/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   turn.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 16:50:23 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/05 05:41:53 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_processturn(t_varlist *vl, double rotspeed)
{
	double	temp;

	if (mlx_is_key_down(vl->mlx, MLX_KEY_LEFT))
	{
		temp = vl->dirx;
		vl->dirx = temp * cos(rotspeed) - vl->diry * sin(rotspeed);
		vl->diry = temp * sin(rotspeed) + vl->diry * cos(rotspeed);
		temp = vl->planex;
		vl->planex = temp * cos(rotspeed) - vl->planey * sin(rotspeed);
		vl->planey = temp * sin(rotspeed) + vl->planey * cos(rotspeed);
	}
	if (mlx_is_key_down(vl->mlx, MLX_KEY_RIGHT))
	{
		temp = vl->dirx;
		vl->dirx = temp * cos(-rotspeed) - vl->diry * sin(-rotspeed);
		vl->diry = temp * sin(-rotspeed) + vl->diry * cos(-rotspeed);
		temp = vl->planex;
		vl->planex = temp * cos(-rotspeed) - vl->planey * sin(-rotspeed);
		vl->planey = temp * sin(-rotspeed) + vl->planey * cos(-rotspeed);
	}
}

void	ft_turnvertical(double ypos, t_varlist *vl)
{
	if (ypos < vl->oldmouseposy)
		if (vl->vaim < 300)
			vl->vaim = vl->vaim + 3;
	if (ypos > vl->oldmouseposy)
		if (vl->vaim > -300)
			vl->vaim = vl->vaim - 3;
	vl->oldmouseposy = ypos;
}

void	ft_turnhorizontal(double xpos, t_varlist *vl)
{
	double	temp;

	if (xpos < vl->oldmouseposx)
	{
		temp = vl->dirx;
		vl->dirx = temp * cos(0.01) - vl->diry * sin(0.01);
		vl->diry = temp * sin(0.01) + vl->diry * cos(0.01);
		temp = vl->planex;
		vl->planex = temp * cos(0.01) - vl->planey * sin(0.01);
		vl->planey = temp * sin(0.01) + vl->planey * cos(0.01);
	}
	if (xpos > vl->oldmouseposx)
	{
		temp = vl->dirx;
		vl->dirx = temp * cos(-0.01) - vl->diry * sin(-0.01);
		vl->diry = temp * sin(-0.01) + vl->diry * cos(-0.01);
		temp = vl->planex;
		vl->planex = temp * cos(-0.01) - vl->planey * sin(-0.01);
		vl->planey = temp * sin(-0.01) + vl->planey * cos(-0.01);
	}
	vl->oldmouseposx = xpos;
}

void	cursorhook(double xpos, double ypos, void *param)
{
	t_varlist	*vl;

	vl = param;
	ft_turnhorizontal(xpos, vl);
	ft_turnvertical(ypos, vl);
}
