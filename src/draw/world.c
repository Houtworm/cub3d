/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   world.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 16:54:20 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/08 05:57:24 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_drawceiling(int x, t_varlist *vl, int drawstart)
{
	int	y;

	y = 0;
	while (y < drawstart)
	{
		mlx_put_pixel(vl->img, x, y, vl->ccolor);
		y++;
	}
	return (y);
}

int	ft_drawwall(int x, t_varlist *vl, int drawstart, int drawend, int y)
{
	int			textx;
	double		step;
	double		textpos;
	int			texty;
	uint32_t	color;

	textx = ft_gettextx(vl);
	step = 64.0 / vl->lineheight;
	textpos = (drawstart - vl->vaim - (vl->jump / vl->walldist) - vl->h / 2 + vl->lineheight / 2) * step;
	while (y < drawend)
	{
		texty = (int)textpos & (64 - 1);
		textpos += step;
		color = ft_gettextcolor(vl->temptext, texty, textx);
		mlx_put_pixel(vl->img, x, y, color);
		y++;
	}
	return (y);
}

void	ft_drawfloor(int x, t_varlist *vl, int y)
{
	while (vl->h > y)
	{
		mlx_put_pixel(vl->img, x, y, vl->fcolor);
		y++;
	}
}

int	ft_getwallheight(t_varlist *vl, int mode)
{
	int	ret;

	if (mode == 1)
	{
		ret = -vl->lineheight / 2 + vl->h / 2 + vl->vaim + (vl->jump / vl->walldist);
		if (ret < 0)
			ret = 0;
	}
	if (mode == 2)
	{
		ret = vl->lineheight / 2 + vl->h / 2 + vl->vaim + (vl->jump / vl->walldist);
		if (ret >= vl->h)
			ret = vl->h - 1;
	}
	return (ret);
}

void	ft_drawmap(t_varlist *vl)
{
	int	x;
	int	y;

	x = 0;
	while (x <= vl->w)
	{
		vl->mapx = (int)vl->posx;
		vl->mapy = (int)vl->posy;
		ft_raycast(vl, x);
		y = ft_drawceiling(x, vl, ft_getwallheight(vl, 1));
		y = ft_drawwall(x, vl, ft_getwallheight(vl, 1), ft_getwallheight(vl, 2), y);
		ft_drawfloor(x, vl, y);
		if (vl->side == 0)
			vl->walldist = (vl->sidedistx - vl->deltadistx);
		else
			vl->walldist = (vl->sidedisty - vl->deltadisty);
		vl->lineheight = vl->h / vl->walldist;
		vl->distance[x] = vl->walldist;
		x++;
	}
}
