/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite1.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 16:54:20 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/10 09:11:46 by houtworm      ########   odam.nl         */
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
		return (vl->decotxt[vl->sprite[i].number]);
	if (vl->sprite[i].type == 1 && vl->sprite[i].status == 1)
		return (vl->decotxt[12]);
	if (vl->sprite[i].type == 2 && vl->sprite[i].status == 0)
		return (vl->picktxt[vl->sprite[i].number]);
	if (vl->sprite[i].type == 3 && vl->sprite[i].status < 2)
		return (vl->gfiretxt[vl->sprite[i].number]);
	return (vl->gdeadtxt[vl->sprite[i].number]);
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
	d->tfx = invdet * (vl->diry * spritex - vl->dirx * spritey);
	d->tfy = invdet * (-vl->planey * spritex + vl->planex * spritey);
	d->sprs = (vl->w / 2) * (1 + d->tfx / d->tfy);
	d->vmov = vl->vaim + vl->jump / d->tfy;
	d->sprh = fabs((vl->h / d->tfy));
	return (d);
}

void	ft_getdrawstartend(t_varlist *vl, t_draw *draw)
{
	draw->drawstarty = -draw->sprh / 2 + vl->h / 2 + draw->vmov;
	if (draw->drawstarty < 0)
		draw->drawstarty = 0;
	draw->drawendy = draw->sprh / 2 + vl->h / 2 + draw->vmov;
	if (draw->drawendy >= vl->h)
		draw->drawendy = vl->h - 1;
	draw->sprw = abs((int)(vl->h / draw->tfy));
	draw->drawstartx = -draw->sprw / 2 + draw->sprs;
	if (draw->drawstartx < 0)
		draw->drawstartx = 0;
	draw->drawendx = draw->sprw / 2 + draw->sprs;
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
		vl->temptxt = ft_getsprite(vl, i);
		ft_drawsprite(vl, draw, x, i);
		free(draw);
		i++;
	}
}
