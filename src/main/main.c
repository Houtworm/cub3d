/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 14:13:07 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/09 02:33:58 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_replaceimage(t_varlist *vl)
{
	mlx_delete_image(vl->mlx, vl->img);
	mlx_delete_image(vl->mlx, vl->fstat);
	mlx_delete_image(vl->mlx, vl->cstat);
	mlx_delete_image(vl->mlx, vl->kstat);
	mlx_delete_image(vl->mlx, vl->tstat);
	mlx_delete_image(vl->mlx, vl->astat);
	mlx_delete_image(vl->mlx, vl->hstat);
	mlx_delete_image(vl->mlx, vl->wimg);
	mlx_delete_image(vl->mlx, vl->mimg);
	mlx_delete_image(vl->mlx, vl->oimg);
	vl->img = mlx_new_image(vl->mlx, vl->w, vl->h);
	vl->oimg = mlx_new_image(vl->mlx, vl->w, vl->h);
	vl->wimg = mlx_new_image(vl->mlx, 64, 64);
	vl->mimg = mlx_new_image(vl->mlx, 22, 22);
}

void	ft_timers(t_varlist *vl)
{
	vl->frametime = vl->mlx->delta_time;
	vl->tottime = vl->tottime + vl->frametime;
}

void	ft_restartgame(t_varlist *vl)
{
	// free some stuff first
	ft_initmainstuff(vl);
	*vl = ft_parseconfigfile(*vl, vl->cubfile);
}

void	mainloop(void *param)
{
	t_varlist	*vl;

	vl = param;
	if (vl->menu == 0)
	{
		ft_replaceimage(vl);
		ft_drawmap(vl);
		ft_checkpickup(vl);
		ft_animateenemies(vl);
		ft_drawsprites(vl);
		ft_drawweapon(vl);
		ft_fireweapon(vl);
		ft_drawminimap(vl);
		ft_checkhealth(vl);
		ft_timers(vl);
		ft_printstats(vl);
		if (!vl->img || (mlx_image_to_window(vl->mlx, vl->img, 0, 0) < 0))
			ft_errorexit("image to window failed ", "mainloop", 1);
		mlx_set_instance_depth(vl->img->instances, 1);
	}
	else if (vl->menu == 3)
		ft_restartgame(vl);
	ft_processinput(vl);
}

int	main(int argc, char **argv)
{
	t_varlist	vl;

	if (argc > 2)
		ft_errorexit("Too many arguments", "", 2);
	vl = initgame();
	if (argc == 2)
		vl = ft_parseconfigfile(vl, argv[1]);
	else
		ft_errorexit("Please include a .cub file ", "", 2);
	vl.backupmap = vl.map;
	if (ft_floodfill(vl))
		ft_errorexit("map is invalid", "floodfill", 1);
	if (!vl.img || (mlx_image_to_window(vl.mlx, vl.img, 0, 0) < 0))
		ft_errorexit("image to window failed ", "main", 1);
	mlx_key_hook(vl.mlx, &keyhook, &vl);
	mlx_resize_hook(vl.mlx, &resizehook, &vl);
	mlx_scroll_hook(vl.mlx, &scrollhook, &vl);
	mlx_set_cursor_mode(vl.mlx, MLX_MOUSE_DISABLED);
	mlx_cursor_hook(vl.mlx, &cursorhook, &vl);
	mlx_loop_hook(vl.mlx, &mainloop, &vl);
	mlx_loop(vl.mlx);
	ft_cleanup(&vl);
	mlx_terminate(vl.mlx);
	exit (0);
}
