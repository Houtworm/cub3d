/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:49:12 by houtworm          #+#    #+#             */
/*   Updated: 2024/03/14 15:51:46 by djonker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_resetgame(t_varlist *vl)
{
	vl->w = 1280;
	vl->h = 720;
	vl->sprite = ft_calloc(4096, 8);
	vl->spritecount = 0;
	vl->distance = ft_calloc(4096, 8);
	vl->ccolor = 0;
	vl->fcolor = 0;
	vl->minimap = 0;
	vl->stats = 0;
	vl->menu = 0;
	vl->flash = 0;
	vl->tottime = 0;
	vl->reloadtime = 0.1;
	vl->firetime = 0;
	vl->reload = 0;
}

void	ft_resettextures(t_varlist *vl)
{
	vl->elevtxt = ft_calloc(4096, 8);
	vl->elevtxt[0] = mlx_load_png("./assets/wall/elevator.png");
	vl->doortxt = ft_calloc(4096, 8);
	vl->doortxt[0] = mlx_load_png("./assets/wall/door.png");
	vl->walltxt = ft_calloc(4096, 8);
	vl->walltxt[0] = NULL;
	vl->walltxt[1] = NULL;
	vl->walltxt[2] = NULL;
	vl->walltxt[3] = NULL;
}

void	ft_resetplayer(t_varlist *vl)
{
	vl->vaim = 0;
	vl->jump = 0;
	vl->treasure = 0;
	vl->tottreasure = 0;
	vl->enemies = 0;
	vl->kills = 0;
	vl->mgun = 0;
	vl->ggun = 0;
	vl->ammo = 10;
	vl->hp = 100;
	vl->weapon = 1;
}

void	ft_resetvars(t_varlist *vl)
{
	ft_resettextures(vl);
	ft_resetplayer(vl);
	ft_resetgame(vl);
}

void	ft_restartgame(t_varlist *vl)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		mlx_delete_image(vl->mlx, vl->mstat[i]);
		i++;
	}
	mlx_delete_image(vl->mlx, vl->oimg);
	mlx_delete_texture(vl->walltxt[0]);
	mlx_delete_texture(vl->walltxt[1]);
	mlx_delete_texture(vl->walltxt[2]);
	mlx_delete_texture(vl->walltxt[3]);
	mlx_delete_texture(vl->elevtxt[0]);
	mlx_delete_texture(vl->doortxt[0]);
	free(vl->distance);
	free(vl->sprite);
	free(vl->walltxt);
	free(vl->elevtxt);
	free(vl->doortxt);
	free(vl->mstat);
	ft_frearr(vl->map);
	ft_resetvars(vl);
	*vl = ft_parseconfigfile(*vl, vl->cubfile);
}
