/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:    :+:            */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:54:20 by houtworm          #+#    #+#             */
/*   Updated: 2024/03/20 02:08:51 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_selecttexture(t_varlist *vl)
{
	if (vl->map[vl->mapx][vl->mapy] == '4')
		vl->temptxt = vl->elevtxt[0];
	else if (vl->map[vl->mapx][vl->mapy] == 'D' ||
			vl->map[vl->mapx][vl->mapy] == 'd')
		vl->temptxt = vl->doortxt[0];
	else if (vl->side == 0)
	{
		if (vl->raydirx > 0)
			vl->temptxt = vl->walltxt[0];
		else
			vl->temptxt = vl->walltxt[2];
	}
	else
	{
		if (vl->raydiry > 0)
			vl->temptxt = vl->walltxt[3];
		else
			vl->temptxt = vl->walltxt[1];
	}
}

int	ft_gettextx(t_varlist *vl)
{
	double	wallx;
	int		textx;

	if (vl->side == 0)
		wallx = vl->posy + vl->wdist * vl->raydiry;
	else
		wallx = vl->posx + vl->wdist * vl->raydirx;
	ft_selecttexture(vl);
	wallx -= floor(wallx);
	textx = wallx * 64.0;
	if (vl->side == 0 && vl->raydirx > 0)
		textx = 64 - textx - 1;
	if (vl->side == 1 && vl->raydiry < 0)
		textx = 64 - textx - 1;
	if (vl->map[vl->mapx][vl->mapy] == 'D' ||
		vl->map[vl->mapx][vl->mapy] == 'd')
	{
		textx += ft_get_door(vl, vl->mapx, vl->mapy)->closedness * 64;
		textx %= 64;
	}
	return (textx);
}

uint32_t	ft_gettextcolor(mlx_texture_t *texture, int texty, int textx)
{
	uint8_t		*texel;
	uint32_t	color;

	texel = &texture->pixels[(texture->width * texty + textx) * 4];
	color = texel[0] << 24 | texel[1] << 16 | texel[2] << 8 | texel[3];
	return (color);
}
