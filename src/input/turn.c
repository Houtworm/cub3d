/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 16:50:23 by houtworm      #+#    #+#                 */
/*   Updated: 2024/03/14 15:52:35 by djonker          ###   ########.fr       */
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
			vl->vaim = vl->vaim + 10;
	if (ypos > vl->oldmouseposy)
		if (vl->vaim > -300)
			vl->vaim = vl->vaim - 10;
	vl->oldmouseposy = ypos;
}

void	ft_turnhorizontal(double xpos, t_varlist *vl)
{
	double	temp;

	if (xpos < vl->oldmouseposx)
	{
		temp = vl->dirx;
		vl->dirx = temp * cos(0.02) - vl->diry * sin(0.02);
		vl->diry = temp * sin(0.02) + vl->diry * cos(0.02);
		temp = vl->planex;
		vl->planex = temp * cos(0.02) - vl->planey * sin(0.02);
		vl->planey = temp * sin(0.02) + vl->planey * cos(0.02);
	}
	if (xpos > vl->oldmouseposx)
	{
		temp = vl->dirx;
		vl->dirx = temp * cos(-0.02) - vl->diry * sin(-0.02);
		vl->diry = temp * sin(-0.02) + vl->diry * cos(-0.02);
		temp = vl->planex;
		vl->planex = temp * cos(-0.02) - vl->planey * sin(-0.02);
		vl->planey = temp * sin(-0.02) + vl->planey * cos(-0.02);
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
