/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:13:07 by houtworm          #+#    #+#             */
/*   Updated: 2023/11/15 19:47:34 by joel             ###   ########.fr       */
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
	mlx_delete_texture(vl->decotxt[0]);
	mlx_delete_texture(vl->decotxt[1]);
	mlx_delete_texture(vl->decotxt[2]);
	mlx_delete_texture(vl->decotxt[3]);
	mlx_delete_texture(vl->decotxt[4]);
	mlx_delete_texture(vl->decotxt[5]);
	mlx_delete_texture(vl->decotxt[6]);
	mlx_delete_texture(vl->decotxt[7]);
	mlx_delete_texture(vl->decotxt[8]);
	mlx_delete_texture(vl->decotxt[9]);
	mlx_delete_texture(vl->decotxt[10]);
	mlx_delete_texture(vl->decotxt[11]);
}

void	ft_deletewalls(t_varlist *vl)
{
	mlx_delete_texture(vl->walltxt[0]);
	mlx_delete_texture(vl->walltxt[1]);
	mlx_delete_texture(vl->walltxt[2]);
	mlx_delete_texture(vl->walltxt[3]);
	mlx_delete_texture(vl->elevtxt[0]);
	mlx_delete_texture(vl->doortxt[0]);
}

void	ft_deletepickup(t_varlist *vl)
{
	mlx_delete_texture(vl->picktxt[0]);
	mlx_delete_texture(vl->picktxt[1]);
	mlx_delete_texture(vl->picktxt[2]);
	mlx_delete_texture(vl->picktxt[3]);
	mlx_delete_texture(vl->picktxt[4]);
	mlx_delete_texture(vl->picktxt[5]);
	mlx_delete_texture(vl->picktxt[6]);
	mlx_delete_texture(vl->picktxt[7]);
	mlx_delete_texture(vl->picktxt[8]);
	mlx_delete_texture(vl->picktxt[9]);
	mlx_delete_texture(vl->picktxt[10]);
	mlx_delete_texture(vl->picktxt[11]);
}

void	ft_cleanup(t_varlist *vl)
{
	ft_deleteimages(vl);
	ft_deletedecor(vl);
	ft_deletewalls(vl);
	ft_deletepickup(vl);
}
