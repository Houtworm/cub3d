/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 16:50:23 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/07 07:06:43 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_moveforward(t_varlist *vl, double movespeed)
{
	if (vl->map[(int)(vl->posx + vl->dirx * movespeed)][(int)vl->posy] == '0')
		vl->posx += vl->dirx * movespeed;
	if (vl->map[(int)vl->posx][(int)(vl->posy + vl->diry * movespeed)] == '0')
		vl->posy += vl->diry * movespeed;
}

void	ft_movebackward(t_varlist *vl, double movespeed)
{
	if (vl->map[(int)(vl->posx - vl->dirx * movespeed)][(int)vl->posy] == '0')
		vl->posx -= vl->dirx * movespeed;
	if (vl->map[(int)vl->posx][(int)(vl->posy - vl->diry * movespeed)] == '0')
		vl->posy -= vl->diry * movespeed;
}

void	ft_moveleft(t_varlist *vl, double movespeed)
{
	if (vl->map[(int)(vl->posx - vl->dirx * movespeed)][(int)vl->posy] == '0')
		vl->posx -= vl->diry * movespeed;
	if (vl->map[(int)vl->posx][(int)(vl->posy + vl->diry * movespeed)] == '0')
		vl->posy += vl->dirx * movespeed;
}

void	ft_moveright(t_varlist *vl, double movespeed)
{
	if (vl->map[(int)(vl->posx + vl->dirx * movespeed)][(int)vl->posy] == '0')
		vl->posx += vl->diry * movespeed;
	if (vl->map[(int)vl->posx][(int)(vl->posy - vl->diry * movespeed)] == '0')
		vl->posy -= vl->dirx * movespeed;
}

void	ft_processmove(t_varlist *vl, double movespeed)
{
	if (mlx_is_key_down(vl->mlx, MLX_KEY_W))
		ft_moveforward(vl, movespeed * vl->run);
	if (mlx_is_key_down(vl->mlx, MLX_KEY_A))
		ft_moveleft(vl, movespeed * vl->run);
	if (mlx_is_key_down(vl->mlx, MLX_KEY_S))
		ft_movebackward(vl, movespeed * vl->run);
	if (mlx_is_key_down(vl->mlx, MLX_KEY_D))
		ft_moveright(vl, movespeed * vl->run);
}
