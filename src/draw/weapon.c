/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   weapon.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 14:13:07 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/10 09:12:33 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_drawweapontexture(t_varlist *vl, mlx_texture_t **text)
{
	int			x;
	int			y;
	int			i;
	uint32_t	color;

	x = 0;
	y = 0;
	i = 1;
	while (i < 4096)
	{
		color = ft_gettextcolor(text[vl->reload], y, x);
		if (color != 0x980088FF)
			mlx_put_pixel(vl->wimg, x, y, color);
		x++;
		if (i % 64 == 0)
		{
			x = 0;
			y++;
		}
		i++;
	}
}

void	ft_drawweapon(t_varlist *vl)
{
	int	size;

	if (vl->weapon == 0)
		ft_drawweapontexture(vl, vl->gun0txt);
	if (vl->weapon == 1)
		ft_drawweapontexture(vl, vl->gun1txt);
	if (vl->weapon == 2)
		ft_drawweapontexture(vl, vl->gun2txt);
	if (vl->weapon == 3)
		ft_drawweapontexture(vl, vl->gun3txt);
	size = vl->h * 0.8;
	mlx_resize_image(vl->wimg, size, size);
	mlx_image_to_window(vl->mlx, vl->wimg, vl->w / 2 - size / 2, vl->h - size);
	mlx_set_instance_depth(vl->wimg->instances, 5);
}
