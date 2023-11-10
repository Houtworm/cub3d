/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 16:54:20 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/10 05:42:09 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_sortsprites(t_varlist *vl)
{
	int			i;
	t_sprite	temp;

	i = 0;
	while (vl->spritecount > i)
	{
		vl->sprite[i].distance = pow((vl->posx - vl->sprite[i].x), 2) + \
								pow((vl->posy - vl->sprite[i].y), 2);
		i++;
	}
	while (i)
	{
		if (vl->sprite[i].distance > vl->sprite[i - 1].distance)
		{
			temp = vl->sprite[i];
			vl->sprite[i] = vl->sprite[i - 1];
			vl->sprite[i - 1] = temp;
		}
		i--;
	}
}

mlx_texture_t	*ft_getsprite(t_varlist *vl, int i)
{
	if (vl->sprite[i].type == 1 && vl->sprite[i].status == 0)
		return (vl->decotext[vl->sprite[i].number]);
	if (vl->sprite[i].type == 1 && vl->sprite[i].status == 1)
		return (vl->decotext[12]);
	if (vl->sprite[i].type == 2 && vl->sprite[i].status == 0)
		return (vl->picktext[vl->sprite[i].number]);
	if (vl->sprite[i].type == 3 && vl->sprite[i].status == 0)
		return (vl->gidletext[vl->sprite[i].number]);
	if (vl->sprite[i].type == 3 && vl->sprite[i].status == 1)
		return (vl->gspottext[vl->sprite[i].number]);
	return (vl->gdeadtext[vl->sprite[i].number]);
}

t_draw	*ft_initdrawsprite(t_varlist *vl, int i)
{
	double			spritex;
	double			spritey;
	double			invdet;
	t_draw			*d;

	d = ft_calloc(12, 8);
	spritex = vl->sprite[i].x - vl->posx;
	spritey = vl->sprite[i].y - vl->posy;
	invdet = 1.0 / (vl->planex * vl->diry - vl->dirx * vl->planey);
	d->transformx = invdet * (vl->diry * spritex - vl->dirx * spritey);
	d->transformy = invdet * (-vl->planey * spritex + vl->planex * spritey);
	d->spritescreen = (vl->w / 2) * (1 + d->transformx / d->transformy);
	d->vmovescreen = vl->vaim + vl->jump / d->transformy;
	d->spriteheight = fabs((vl->h / d->transformy));
	return (d);
}

void	ft_getdrawstartend(t_varlist *vl, t_draw *draw)
{
	draw->drawstarty = -draw->spriteheight / 2 + vl->h / 2 + draw->vmovescreen;
	if (draw->drawstarty < 0)
		draw->drawstarty = 0;
	draw->drawendy = draw->spriteheight / 2 + vl->h / 2 + draw->vmovescreen;
	if (draw->drawendy >= vl->h)
		draw->drawendy = vl->h - 1;
	draw->spritewidth = abs((int)(vl->h / draw->transformy));
	draw->drawstartx = -draw->spritewidth / 2 + draw->spritescreen;
	if (draw->drawstartx < 0)
		draw->drawstartx = 0;
	draw->drawendx = draw->spritewidth / 2 + draw->spritescreen;
	if (draw->drawendx >= vl->w)
		draw->drawendx = vl->w - 1;
}

void	ft_drawsprites(t_varlist *vl)
{
	int				i;
	int				x;
	t_draw			*draw;

	ft_sortsprites(vl);
	i = 0;
	while (vl->spritecount > i)
	{
		draw = ft_initdrawsprite(vl, i);
		ft_getdrawstartend(vl, draw);
		x = draw->drawstartx;
		vl->temptext = ft_getsprite(vl, i);
		ft_drawsprite(vl, draw, x, i);
		free(draw);
		i++;
	}
}
