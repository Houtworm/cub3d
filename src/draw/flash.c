/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flash.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 14:13:07 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/09 22:26:43 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

uint32_t	ft_flashred(t_varlist *vl)
{
	uint32_t	color;

	if (vl->flash == 6)
		color = 0xFF000066;
	else if (vl->flash == 5)
		color = 0xFF000055;
	else if (vl->flash == 4)
		color = 0xFF000044;
	else if (vl->flash == 3)
		color = 0xFF000033;
	else if (vl->flash == 2)
		color = 0xFF000022;
	else
		color = 0xFF000011;
	return (color);
}

uint32_t	ft_flashgreen(t_varlist *vl)
{
	uint32_t	color;

	if (vl->flash == 6)
		color = 0x00FF0066;
	else if (vl->flash == 5)
		color = 0x00FF0055;
	else if (vl->flash == 4)
		color = 0x00FF0044;
	else if (vl->flash == 3)
		color = 0x00FF0033;
	else if (vl->flash == 2)
		color = 0x00FF0022;
	else
		color = 0x00FF0011;
	return (color);
}

uint32_t	ft_flashblue(t_varlist *vl)
{
	uint32_t	color;

	if (vl->flash == 6)
		color = 0x0000FF66;
	else if (vl->flash == 5)
		color = 0x0000FF55;
	else if (vl->flash == 4)
		color = 0x0000FF44;
	else if (vl->flash == 3)
		color = 0x0000FF33;
	else if (vl->flash == 2)
		color = 0x0000FF22;
	else
		color = 0x0000FF11;
	return (color);
}

uint32_t	ft_flashyellow(t_varlist *vl)
{
	uint32_t	color;

	if (vl->flash == 6)
		color = 0xFFFF0066;
	else if (vl->flash == 5)
		color = 0xFFFF0055;
	else if (vl->flash == 4)
		color = 0xFFFF0044;
	else if (vl->flash == 3)
		color = 0xFFFF0033;
	else if (vl->flash == 2)
		color = 0xFFFF0022;
	else
		color = 0xFFFF0011;
	return (color);
}

void	ft_flashscreen(t_varlist *vl, int x, int y, uint32_t color)
{
	if (vl->flash)
	{
		vl->fimg = mlx_new_image(vl->mlx, vl->w, vl->h);
		if (vl->flashcolor == 1)
			color = ft_flashred(vl);
		else if (vl->flashcolor == 2)
			color = ft_flashgreen(vl);
		else if (vl->flashcolor == 3)
			color = ft_flashblue(vl);
		else
			color = ft_flashyellow(vl);
		while (y < vl->h)
		{
			x = 0;
			while (x < vl->w)
			{
				mlx_put_pixel(vl->fimg, x, y, color);
				x++;
			}
			y++;
		}
		mlx_image_to_window(vl->mlx, vl->fimg, 0, 0);
		mlx_set_instance_depth(vl->fimg->instances, 15);
		vl->flash--;
	}
}
