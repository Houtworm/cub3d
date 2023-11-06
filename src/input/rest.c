/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rest.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 16:50:23 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/06 01:05:43 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_processacro(t_varlist *vl, double movespeed)
{
	if (mlx_is_key_down(vl->mlx, MLX_KEY_SPACE) && vl->jump < 10)
		vl->jump = 200;
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

void	ft_processguns(t_varlist *vl)
{
	if (mlx_is_mouse_down(vl->mlx, MLX_MOUSE_BUTTON_LEFT) && vl->reload == 0)
	{
		if (vl->ammo || !vl->weapon)
		{
			vl->anitime = vl->frametime;
			vl->reload = 1;
		}
	}
	if (mlx_is_mouse_down(vl->mlx, MLX_MOUSE_BUTTON_RIGHT))
		ft_putendl("zoom");
}

void	ft_nextweapon(t_varlist *vl)
{
	if (vl->weapon == 0)
		vl->weapon = 1;
	else if (vl->weapon == 1)
	{
		if (vl->mgun == 1)
			vl->weapon = 2;
		else if (vl->ggun == 1)
			vl->weapon = 3;
		else
			vl->weapon = 0;
	}
	else if (vl->weapon == 2)
	{
		if (vl->ggun == 1)
			vl->weapon = 3;
		else
			vl->weapon = 0;
	}
	else if (vl->weapon == 3)
		vl->weapon = 0;
}

void	ft_prevweapon(t_varlist *vl)
{
	if (vl->weapon == 0)
	{
		if (vl->ggun == 1)
			vl->weapon = 3;
		else if (vl->mgun == 1)
			vl->weapon = 2;
		else
			vl->weapon = 1;
	}
	else if (vl->weapon == 1)
		vl->weapon = 0;
	else if (vl->weapon == 2)
		vl->weapon = 1;
	else if (vl->weapon == 3)
	{
		if (vl->mgun == 1)
			vl->weapon = 2;
		else
			vl->weapon = 1;
	}
}

void	scrollhook(double xdelta, double ydelta, void *param)
{
	t_varlist	*vl;

	vl = param;
	vl = vl;
	xdelta++;
	if (ydelta > 0)
		ft_prevweapon(vl);
	if (ydelta < 0)
		ft_nextweapon(vl);
}
