/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 16:54:20 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/05 23:26:38 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_selecttexture(t_varlist *vl)
{
	if (vl->side == 0)
	{
		if (vl->raydirx > 0)
			vl->temptext = vl->walltext[0];
		else
			vl->temptext = vl->walltext[2];
	}
	else
	{
		if (vl->raydiry > 0)
			vl->temptext = vl->walltext[3];
		else
			vl->temptext = vl->walltext[1];
	}
}

int	ft_gettextx(t_varlist *vl)
{
	double	wallx;
	int		textx;

	if (vl->side == 0)
		wallx = vl->posy + vl->walldist * vl->raydiry;
	else
		wallx = vl->posx + vl->walldist * vl->raydirx;
	ft_selecttexture(vl);
	wallx -= floor(wallx);
	textx = wallx * 64.0;
	if (vl->side == 0 && vl->raydirx > 0)
		textx = 64 - textx - 1;
	if (vl->side == 1 && vl->raydiry < 0)
		textx = 64 - textx - 1;
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
