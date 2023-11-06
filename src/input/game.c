/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 16:50:23 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/05 20:16:38 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	keyhook(mlx_key_data_t kd, void *param)
{
	t_varlist	*vl;

	vl = param;
	vl->w = vl->w;
	if (mlx_is_key_down(vl->mlx, MLX_KEY_ESCAPE))
	{
		ft_putendl("escape is pressed");
		mlx_close_window(vl->mlx);
		return ;
	}
	if ((kd.key == MLX_KEY_H || kd.key == MLX_KEY_F1) && kd.action == MLX_PRESS)
		ft_putendl("H is pressed");
}

void	resizehook(int x, int y, void *param)
{
	t_varlist	*vl;

	vl = param;
	vl->h = y;
	vl->w = x;
	vl->mlx->height = y;
	vl->mlx->width = x;
}

void	ft_processinput(t_varlist *vl)
{
	double	movespeed;
	double	rotspeed;

	movespeed = vl->frametime * 3.0;
	rotspeed = vl->frametime * 3.0;
	ft_processacro(vl, movespeed);
	ft_processmove(vl, rotspeed);
	ft_processturn(vl, rotspeed);
	ft_processguns(vl);
}
