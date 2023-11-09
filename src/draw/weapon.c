/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   weapon.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 14:13:07 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/09 00:59:42 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_drawknife(t_varlist *vl)
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
		color = ft_gettextcolor(vl->gun0text[vl->reload], y, x);
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

void	ft_drawpistol(t_varlist *vl)
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
		color = ft_gettextcolor(vl->gun1text[vl->reload], y, x);
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

void	ft_drawmgun(t_varlist *vl)
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
		color = ft_gettextcolor(vl->gun2text[vl->reload], y, x);
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

void	ft_drawggun(t_varlist *vl)
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
		color = ft_gettextcolor(vl->gun3text[vl->reload], y, x);
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
		ft_drawknife(vl);
	if (vl->weapon == 1)
		ft_drawpistol(vl);
	if (vl->weapon == 2)
		ft_drawmgun(vl);
	if (vl->weapon == 3)
		ft_drawggun(vl);
	size = vl->h * 0.8;
	mlx_resize_image(vl->wimg, size, size);
	mlx_image_to_window(vl->mlx, vl->wimg, vl->w / 2 - size / 2, vl->h - size);
	mlx_set_instance_depth(vl->wimg->instances, 5);
}
