/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 16:54:20 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/09 20:29:24 by houtworm      ########   odam.nl         */
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
		vl->sprite[i].distance = pow((vl->posx - vl->sprite[i].x), 2) + pow((vl->posy - vl->sprite[i].y), 2);
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
