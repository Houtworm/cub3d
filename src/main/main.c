/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 14:13:07 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/08 04:03:29 by houtworm      ########   odam.nl         */
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
	vl->img = mlx_new_image(vl->mlx, vl->w, vl->h);
	vl->wimg = mlx_new_image(vl->mlx, 64, 64);
	vl->mimg = mlx_new_image(vl->mlx, 22, 22);
}

void	ft_timers(t_varlist *vl)
{
	vl->frametime = vl->mlx->delta_time;
	vl->tottime = vl->tottime + vl->frametime;
}

void	mainloop(void *param)
{
	t_varlist	*vl;

	vl = param;
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
	ft_processinput(vl);
	if (!vl->img || (mlx_image_to_window(vl->mlx, vl->img, 0, 0) < 0))
		ft_errorexit("image to window failed ", "mainloop", 1);
	mlx_set_instance_depth(vl->img->instances, 1);
}

int	ft_flood(char **fillmap, int x, int y)
{
	if (fillmap[y - 1][x] == '0' || fillmap[y][x] == '3')
	{

		fillmap[y - 1][x] = 'F';
		if (ft_flood(fillmap, x, y - 1))
			return (1);
	}
	if (fillmap[y + 1][x] == '0' || fillmap[y][x] == '3')
	{

		fillmap[y + 1][x] = 'F';
		if (ft_flood(fillmap, x, y + 1))
			return (1);
	}
	if (fillmap[y][x - 1] == '0' || fillmap[y][x] == '3')
	{

		fillmap[y][x - 1] = 'F';
		if (ft_flood(fillmap, x - 1, y))
			return (1);
	}
	if (fillmap[y][x + 1] == '0' || fillmap[y][x] == '3')
	{
		fillmap[y][x + 1] = 'F';
		if (ft_flood(fillmap, x + 1, y))
			return (1);
	}
	return (0);
}

int	ft_floodfill(t_varlist vl)
{
	int		y;
	int		x;
	char	**fillmap;

	fillmap = ft_calloc(1024, 8);
	y = 0;
	while (vl.map[y])
	{
		fillmap[y] = ft_strdup(vl.map[y]);
		y++;
	}
	y = (int)vl.posy;
	x = (int)vl.posx;
	if (fillmap[y][x] == '0' || fillmap[y][x] == '3')
	{
		fillmap[y][x] = 'F';
		if (ft_flood(fillmap, x, y))
			return (1);
	}
	else
		return (1);
	return (0);
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
