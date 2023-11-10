/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   world.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 16:54:20 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/10 10:41:13 by houtworm      ########   odam.nl         */
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

int	ft_drawwall(t_varlist *vl, int x, int y, t_draw *draw)
{
	int			textx;
	double		step;
	double		textpos;
	int			texty;
	uint32_t	color;

	textx = ft_gettextx(vl);
	step = 64.0 / vl->lineh;
	textpos = (draw->drawstarty - vl->vaim - (vl->jump / vl->wdist) - \
							vl->h / 2 + vl->lineh / 2) * step;
	while (y < draw->drawendy)
	{
		texty = (int)textpos & (64 - 1);
		textpos += step;
		color = ft_gettextcolor(vl->temptxt, texty, textx);
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
		ret = -vl->lineh / 2 + vl->h / 2 + vl->vaim + (vl->jump / vl->wdist);
		if (ret < 0)
			ret = 0;
	}
	if (mode == 2)
	{
		ret = vl->lineh / 2 + vl->h / 2 + vl->vaim + (vl->jump / vl->wdist);
		if (ret >= vl->h)
			ret = vl->h - 1;
	}
	return (ret);
}

void	ft_drawmap(t_varlist *vl)
{
	int		x;
	int		y;
	t_draw	*draw;

	x = 0;
	draw = ft_calloc(12, 8);
	while (x <= vl->w)
	{
		vl->mapx = (int)vl->posx;
		vl->mapy = (int)vl->posy;
		ft_raycast(vl, x);
		y = ft_drawceiling(x, vl, ft_getwallheight(vl, 1));
		draw->drawstarty = ft_getwallheight(vl, 1);
		draw->drawendy = ft_getwallheight(vl, 2);
		y = ft_drawwall(vl, x, y, draw);
		ft_drawfloor(x, vl, y);
		if (vl->side == 0)
			vl->wdist = (vl->sidedistx - vl->deltadistx);
		else
			vl->wdist = (vl->sidedisty - vl->deltadisty);
		vl->lineh = vl->h / vl->wdist;
		vl->distance[x] = vl->wdist;
		x++;
	}
	free(draw);
}
