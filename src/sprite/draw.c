/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 16:54:20 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/09 23:06:41 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_drawspriteline(t_varlist *vl, t_draw *draw, int y, int x)
{
	int				d;
	uint8_t			*texel;
	uint32_t		color;

	d = (y - draw->vmovescreen) * 256 - vl->h * 128 + draw->spriteheight * 128;
	draw->texy = (d * 64) / draw->spriteheight / 256;
	if (draw->texy < 0)
		draw->texy = 0;
	if (draw->texy > 64)
		draw->texy = 64;
	if (draw->texx < 0)
		draw->texx = 0;
	if (draw->texx > 64)
		draw->texx = 64;
	texel = &vl->temptext->pixels[(vl->temptext->width * draw->texy + draw->texx) * 4];
	color = texel[0] << 24 | texel[1] << 16 | texel[2] << 8 | texel[3];
	if (color != 0x980088FF)
		mlx_put_pixel(vl->img, x, y, color);
}

void	ft_drawsprite(t_varlist *vl, t_draw *draw, int x, int i)
{
	int				y;

	while (x < draw->drawendx)
	{
		draw->texx = (int)(256 * (x - (-draw->spritewidth / 2 + draw->spritescreen)) * 64 / draw->spritewidth) / 256;
		if (draw->transformy > 0 && x > 0 && x < vl->w && draw->transformy < vl->distance[x] + 0.7)
		{
			if (vl->sprite[i].type == 3 && vl->sprite[i].status == 0)
				vl->sprite[i].status = 1;
			y = draw->drawstarty;
			while (y < draw->drawendy)
			{
				ft_drawspriteline(vl, draw, y, x);
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
	t_draw			*draw;

	draw = ft_calloc(12, 8);
	spritex = vl->sprite[i].x - vl->posx;
	spritey = vl->sprite[i].y - vl->posy;
	invdet = 1.0 / (vl->planex * vl->diry - vl->dirx * vl->planey);
	draw->transformx = invdet * (vl->diry * spritex - vl->dirx * spritey);
	draw->transformy = invdet * (-vl->planey * spritex + vl->planex * spritey);
	draw->spritescreen = (vl->w / 2) * (1 + draw->transformx / draw->transformy);
	draw->vmovescreen = vl->vaim + vl->jump / draw->transformy;
	draw->spriteheight = fabs((vl->h / draw->transformy));
	return (draw);
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
