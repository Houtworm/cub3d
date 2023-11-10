/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mouse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 16:50:23 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/10 05:16:15 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_processguns(t_varlist *vl)
{
	if (mlx_is_mouse_down(vl->mlx, MLX_MOUSE_BUTTON_LEFT) && vl->reload == 0)
	{
		if (vl->ammo || !vl->weapon)
			vl->reload = 1;
		if (!vl->ammo && vl->weapon)
		{
			vl->weapon = 0;
			vl->reloadtime = 0.05;
		}
	}
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
	if (vl->weapon == 0)
		vl->reloadtime = 0.05;
	else if (vl->weapon == 1)
		vl->reloadtime = 0.1;
	else if (vl->weapon == 2)
		vl->reloadtime = 0.05;
	else if (vl->weapon == 3)
		vl->reloadtime = 0.02;
}
