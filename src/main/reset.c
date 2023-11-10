/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reset.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 16:49:12 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/10 08:00:23 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_resetgame(t_varlist *vl)
{
	vl->w = 800;
	vl->h = 600;
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
	vl->elevtext = ft_calloc(4096, 8);
	vl->elevtext[0] = mlx_load_png("./assets/wall/elevator.png");
	vl->walltext = ft_calloc(4096, 8);
	vl->walltext[0] = NULL;
	vl->walltext[1] = NULL;
	vl->walltext[2] = NULL;
	vl->walltext[3] = NULL;
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
	mlx_delete_texture(vl->walltext[0]);
	mlx_delete_texture(vl->walltext[1]);
	mlx_delete_texture(vl->walltext[2]);
	mlx_delete_texture(vl->walltext[3]);
	mlx_delete_texture(vl->elevtext[0]);
	free(vl->distance);
	free(vl->sprite);
	free(vl->walltext);
	free(vl->elevtext);
	free(vl->mstat);
	ft_frearr(vl->map);
	ft_resetvars(vl);
	*vl = ft_parseconfigfile(*vl, vl->cubfile);
}
