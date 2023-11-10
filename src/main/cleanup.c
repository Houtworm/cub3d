/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 14:13:07 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/10 03:47:23 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_deleteimages(t_varlist *vl)
{
	int	i;

	i = 0;
	if (vl->menu)
	{
		while (i < 8)
		{
			mlx_delete_image(vl->mlx, vl->mstat[i]);
			i++;
		}
		free(vl->mstat);
	}
	mlx_delete_image(vl->mlx, vl->img);
	mlx_delete_image(vl->mlx, vl->oimg);
	mlx_delete_image(vl->mlx, vl->wimg);
	mlx_delete_image(vl->mlx, vl->mimg);
}

void	ft_deletedecor(t_varlist *vl)
{
	mlx_delete_texture(vl->decotext[0]);
	mlx_delete_texture(vl->decotext[1]);
	mlx_delete_texture(vl->decotext[2]);
	mlx_delete_texture(vl->decotext[3]);
	mlx_delete_texture(vl->decotext[4]);
	mlx_delete_texture(vl->decotext[5]);
	mlx_delete_texture(vl->decotext[6]);
	mlx_delete_texture(vl->decotext[7]);
	mlx_delete_texture(vl->decotext[8]);
	mlx_delete_texture(vl->decotext[9]);
	mlx_delete_texture(vl->decotext[10]);
	mlx_delete_texture(vl->decotext[11]);
}

void	ft_deletewalls(t_varlist *vl)
{
	mlx_delete_texture(vl->walltext[0]);
	mlx_delete_texture(vl->walltext[1]);
	mlx_delete_texture(vl->walltext[2]);
	mlx_delete_texture(vl->walltext[3]);
	mlx_delete_texture(vl->elevtext[0]);
}

void	ft_deletepickup(t_varlist *vl)
{
	mlx_delete_texture(vl->picktext[0]);
	mlx_delete_texture(vl->picktext[1]);
	mlx_delete_texture(vl->picktext[2]);
	mlx_delete_texture(vl->picktext[3]);
	mlx_delete_texture(vl->picktext[4]);
	mlx_delete_texture(vl->picktext[5]);
	mlx_delete_texture(vl->picktext[6]);
	mlx_delete_texture(vl->picktext[7]);
	mlx_delete_texture(vl->picktext[8]);
	mlx_delete_texture(vl->picktext[9]);
	mlx_delete_texture(vl->picktext[10]);
	mlx_delete_texture(vl->picktext[11]);
}

void	ft_cleanup(t_varlist *vl)
{
	ft_deleteimages(vl);
	ft_deletedecor(vl);
	ft_deletewalls(vl);
	ft_deletepickup(vl);
}
