/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 16:54:20 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/10 07:24:55 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_drawspriteline(t_varlist *vl, t_draw *d, int y, int x)
{
	int				t;
	uint8_t			*texel;
	uint32_t		color;

	t = (y - d->vmovescreen) * 256 - vl->h * 128 + d->sprh * 128;
	d->y = (t * 64) / d->sprh / 256;
	if (d->y < 0)
		d->y = 0;
	if (d->y > 64)
		d->y = 64;
	if (d->x < 0)
		d->x = 0;
	if (d->x > 64)
		d->x = 64;
	texel = &vl->temptext->pixels[(vl->temptext->width * d->y + d->x) * 4];
	color = texel[0] << 24 | texel[1] << 16 | texel[2] << 8 | texel[3];
	if (color != 0x980088FF)
		mlx_put_pixel(vl->img, x, y, color);
}

void	ft_drawsprite(t_varlist *vl, t_draw *d, int x, int i)
{
	int				y;

	while (x < d->drawendx)
	{
		d->x = (int)(256 * (x - (-d->sprw / 2 + d->sscr)) * 64 / d->sprw) / 256;
		if (d->tfy > 0 && x > 0 && x < vl->w && d->tfy < vl->distance[x] + 0.7)
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
