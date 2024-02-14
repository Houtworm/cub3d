/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 14:13:07 by houtworm      #+#    #+#                 */
/*   Updated: 2024/02/14 17:50:32 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_newframe(t_varlist *vl)
{
	mlx_delete_image(vl->mlx, vl->img);
	mlx_delete_image(vl->mlx, vl->fstat);
	mlx_delete_image(vl->mlx, vl->cstat);
	mlx_delete_image(vl->mlx, vl->kstat);
	mlx_delete_image(vl->mlx, vl->tstat);
	mlx_delete_image(vl->mlx, vl->astat);
	mlx_delete_image(vl->mlx, vl->hstat);
	mlx_delete_image(vl->mlx, vl->wimg);
	mlx_delete_image(vl->mlx, vl->fimg);
	mlx_delete_image(vl->mlx, vl->mimg);
	vl->img = mlx_new_image(vl->mlx, vl->w, vl->h);
	vl->wimg = mlx_new_image(vl->mlx, 64, 64);
	vl->mimg = mlx_new_image(vl->mlx, 22, 22);
	vl->frametime = vl->mlx->delta_time;
	vl->tottime = vl->tottime + vl->frametime;
}

void	ft_imagetowindow(t_varlist *vl)
{
	if (!vl->img || (mlx_image_to_window(vl->mlx, vl->img, 0, 0) < 0))
		ft_errorexit("image to window failed ", "mainloop", 1);
	mlx_set_instance_depth(vl->img->instances, 1);
}

void	ft_printall(t_varlist *vl)
{
	printf("\n\n\n");
	printf("posx: %f\n", vl->posx);
	printf("posy: %f\n", vl->posy);
	printf("dirx: %f\n", vl->dirx);
	printf("diry: %f\n", vl->diry);
	printf("planex: %f\n", vl->planex);
	printf("planey: %f\n", vl->planey);
	printf("raydirx: %f\n", vl->raydirx);
	printf("raydiry: %f\n", vl->raydiry);
	printf("sidedistx: %f\n", vl->sidedistx);
	printf("sidedisty: %f\n", vl->sidedisty);
	printf("deltadistx: %f\n", vl->deltadistx);
	printf("deltadisty: %f\n", vl->deltadisty);
	printf("wdist: %f\n", vl->wdist);
	printf("side: %d\n", vl->side);
	printf("lineh: %d\n", vl->lineh);
	printf("distance: %d\n", *vl->distance);
}

void	mainloop(void *param)
{
	t_varlist	*vl;

	vl = param;
	ft_processinput(vl);
	if (!vl->menu)
	{
		ft_newframe(vl);
		ft_drawmap(vl);
		/*ft_processdoors(vl);*/ // here we check every door struct instance, animate it
		ft_enemyaction(vl);
		ft_checkpickup(vl);
		ft_drawsprites(vl);
		ft_drawweapon(vl);
		ft_fireweapon(vl);
		ft_drawminimap(vl);
		ft_checkhealth(vl);
		ft_printstats(vl);
		ft_flashscreen(vl, 0, 0, 0);
		ft_imagetowindow(vl);
		ft_printall(vl);
	}
	else if (vl->menu == 3)
		ft_restartgame(vl);
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
	vl.cubfile = ft_strdup(argv[1]);
	if (ft_floodfill(vl))
		ft_errorexit("map is invalid", "floodfill", 1);
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
