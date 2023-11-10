/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 16:54:20 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/10 03:09:30 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_drawspriteline(t_varlist *vl, t_draw *d, int y, int x)
{
	int				t;
	uint8_t			*texel;
	uint32_t		color;

	t = (y - d->vmovescreen) * 256 - vl->h * 128 + d->spriteheight * 128;
	d->texy = (t * 64) / d->spriteheight / 256;
	if (d->texy < 0)
		d->texy = 0;
	if (d->texy > 64)
		d->texy = 64;
	if (d->texx < 0)
		d->texx = 0;
	if (d->texx > 64)
		d->texx = 64;
	texel = &vl->temptext->pixels[(vl->temptext->width * d->texy + d->texx) * 4];
	color = texel[0] << 24 | texel[1] << 16 | texel[2] << 8 | texel[3];
	if (color != 0x980088FF)
		mlx_put_pixel(vl->img, x, y, color);
}

void	ft_drawsprite(t_varlist *vl, t_draw *d, int x, int i)
{
	int				y;

	while (x < d->drawendx)
	{
		d->texx = (int)(256 * (x - (-d->spritewidth / 2 + d->spritescreen)) * 64 / d->spritewidth) / 256;
		if (d->transformy > 0 && x > 0 && x < vl->w && d->transformy < vl->distance[x] + 0.7)
		{
			if (vl->sprite[i].type == 3 && vl->sprite[i].status == 0)
				vl->sprite[i].status = 1;
			y = d->drawstarty;
			while (y < d->drawendy)
			{
				ft_drawspriteline(vl, d, y, x);
				y++;
			}
		}
		else if (vl->sprite[i].type == 3 && vl->sprite[i].status < 2)
		{
			vl->sprite[i].status = 0;
			vl->sprite[i].number = 0;
		}
		x++;
	}
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
