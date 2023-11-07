/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 14:13:07 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/07 18:22:17 by houtworm      ########   odam.nl         */
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
	vl->img = mlx_new_image(vl->mlx, vl->w, vl->h);
	vl->wimg = mlx_new_image(vl->mlx, 64, 64);
}

void	ft_printmap(t_varlist *vl)
{
	int	i;

	i = 0;
	while (vl->map[i])
	{
		ft_putendl(vl->map[i]);
		i++;
	}
	double	movespeed;
	movespeed = vl->frametime * 3.0;
	printf("side: %d\n", vl->side);
	printf("raydirx: %lf\n", vl->raydirx);
	printf("raydiry: %lf\n", vl->raydiry);
	printf("forward:  x: %c, y: %c\n", vl->map[(int)(vl->posx + vl->dirx * movespeed)][(int)vl->posy], vl->map[(int)vl->posx][(int)(vl->posy + vl->diry * movespeed)]);
	printf("backward: x: %c, y: %c\n", vl->map[(int)(vl->posx - vl->dirx * movespeed)][(int)vl->posy], vl->map[(int)vl->posx][(int)(vl->posy - vl->diry * movespeed)]);
	printf("left:     x: %c, y: %c\n", vl->map[(int)(vl->posx - vl->dirx * movespeed)][(int)vl->posy], vl->map[(int)vl->posx][(int)(vl->posy + vl->diry * movespeed)]);
	printf("right:    x: %c, y: %c\n", vl->map[(int)(vl->posx + vl->dirx * movespeed)][(int)vl->posy], vl->map[(int)vl->posx][(int)(vl->posy - vl->diry * movespeed)]);
}

void	ft_timers(t_varlist *vl)
{
	char	*time;
	char	*temp;

	vl->frametime = vl->mlx->delta_time;
	vl->tottime = vl->tottime + vl->frametime;
	time = ft_itoa(vl->tottime);
	temp = ft_vastrjoin(3, "Time: ", time, " Seconds");
	vl->tstat = mlx_put_string(vl->mlx, temp, 10, 70);
	mlx_set_instance_depth(vl->tstat->instances, 5);
	ft_vafree(2, time, temp);
}

void	ft_fireweapon(t_varlist *vl)
{
	if (vl->reload)
	{
		if (vl->tottime - vl->firetime > vl->reloadtime)
		{
			vl->firetime = vl->tottime;
			vl->reload++;
			if (vl->reload == 2)
			{
				if (vl->weapon)
					vl->ammo--;
				ft_firebullet(vl);
			}
			if (vl->reload > 4)
				vl->reload = 0;
		}
	}

}

void	ft_animateenemies(t_varlist *vl)
{
	int	i;

	i = 0;
	while (vl->spritecount > i)
	{
		if (vl->sprite[i].status)
		{
			if (vl->sprite[i].status == 1)
			{
				if (vl->tottime - vl->sprite[i].anitime > 0.8)
				{
					vl->sprite[i].anitime = vl->tottime;
					vl->sprite[i].number++;
					if (vl->sprite[i].number == 4)
						vl->sprite[i].number = 2;
					else if (vl->sprite[i].number == 3)
						vl->hp = vl->hp - 10;
				}
			}
			if (vl->sprite[i].status == 2)
			{
				if (vl->tottime - vl->sprite[i].anitime > 0.2 && vl->sprite[i].number < 4)
				{
					vl->sprite[i].anitime = vl->tottime;
					vl->sprite[i].number++;
				}
			}
		}
		i++;
	}
}

void	ft_checkhealth(t_varlist *vl)
{
	if (vl->hp <= 0)
	{
		ft_putendl("You died!");
		mlx_close_window(vl->mlx);
		return ;
	}
}

void	mainloop(void *param)
{
	t_varlist	*vl;

	vl = param;
	ft_replaceimage(vl);
	ft_drawmap(vl);
	ft_checkpickup(vl);
	/*ft_enemyaction(vl);*/
	ft_animateenemies(vl);
	ft_drawsprites(vl);
	ft_drawweapon(vl);
	ft_fireweapon(vl);
	/*ft_drawminimap(vl);*/
	ft_checkhealth(vl);
	ft_timers(vl);
	ft_printstats(vl);
	ft_processinput(vl);
	/*ft_printmap(vl);*/
	if (!vl->img || (mlx_image_to_window(vl->mlx, vl->img, 0, 0) < 0))
		ft_errorexit("image to window failed ", "mainloop", 1);
	mlx_set_instance_depth(vl->img->instances, 1);
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
