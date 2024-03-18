/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 16:50:23 by houtworm      #+#    #+#                 */
/*   Updated: 2024/03/18 19:34:41 by djonker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	keyhook(mlx_key_data_t kd, void *param)
{
	t_varlist	*vl;

	vl = param;
	if (mlx_is_key_down(vl->mlx, MLX_KEY_ESCAPE))
	{
		ft_putendl("escape is pressed");
		mlx_close_window(vl->mlx);
		return ;
	}
	if (vl->menu == 0)
	{
		if (kd.key == MLX_KEY_M && kd.action == MLX_PRESS)
			vl->minimap++;
		if (kd.key == MLX_KEY_N && kd.action == MLX_PRESS)
			vl->stats++;
		if (kd.key == MLX_KEY_F && kd.action == MLX_PRESS)
			ft_interact(vl);
	}
}

void	resizehook(int x, int y, void *param)
{
	t_varlist	*vl;

	vl = param;
	param = vl;
	x=x;
	y=y;
	/*vl->h = y;*/
	/*vl->w = x;*/
	/*vl->mlx->height = y;*/
	/*vl->mlx->width = x;*/
}

void	ft_processinput(t_varlist *vl)
{
	double	movespeed;
	double	rotspeed;

	movespeed = vl->frametime * 3.0;
	rotspeed = vl->frametime * 3.0;
	ft_processacro(vl, movespeed);
	if (vl->menu == 0)
	{
		ft_processmove(vl, rotspeed, 0, 0);
		ft_processturn(vl, rotspeed);
		ft_processguns(vl);
	}
}
