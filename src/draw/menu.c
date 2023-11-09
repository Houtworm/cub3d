/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   finish.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 14:13:07 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/09 08:34:24 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_printstats1(t_varlist *vl)
{
	char	*total;
	char	*current;
	char	*temp;

	current = ft_itoa(vl->tottime);
	temp = ft_vastrjoin(3, "Time: ", current, " Seconds");
	vl->mstat[1] = mlx_put_string(vl->mlx, temp, vl->w / 2 - 100, 180);
	mlx_resize_image(vl->mstat[1], 200, 50);
	ft_vafree(2, current, temp);
	total = ft_itoa(vl->enemies);
	current = ft_itoa(vl->kills);
	temp = ft_vastrjoin(4, "Nazis Killed: ", current, "/", total);
	vl->mstat[2] = mlx_put_string(vl->mlx, temp, vl->w / 2 - 100, 230);
	mlx_resize_image(vl->mstat[2], 200, 50);
	ft_vafree(3, temp, total, current);
	total = ft_itoa(vl->tottreasure);
	current = ft_itoa(vl->treasure);
	temp = ft_vastrjoin(4, "Treasure found: ", current, "/", total);
	vl->mstat[3] = mlx_put_string(vl->mlx, temp, vl->w / 2 - 100, 280);
	mlx_resize_image(vl->mstat[3], 200, 50);
	ft_vafree(3, temp, total, current);
}

void	ft_printstats2(t_varlist *vl)
{
	char	*current;
	char	*temp;

	current = ft_itoa(vl->ammo);
	temp = ft_vastrjoin(2, "Ammo left: ", current);
	vl->mstat[4] = mlx_put_string(vl->mlx, temp, vl->w / 2 - 100, 330);
	mlx_resize_image(vl->mstat[4], 200, 50);
	ft_vafree(2, temp, current);
	current = ft_itoa(vl->hp);
	temp = ft_vastrjoin(2, "HP left: ", current);
	vl->mstat[5] = mlx_put_string(vl->mlx, temp, vl->w / 2 - 100, 380);
	mlx_resize_image(vl->mstat[5], 200, 50);
	ft_vafree(2, temp, current);
}

void	ft_printscore(t_varlist *vl)
{
	int		score;
	char	*scor;
	char	*temp;

	score = (vl->treasure * 10000) + (vl->kills * 1000);
	score = score + (vl->ammo * 100) + (vl->hp * 100);
	score = score - (vl->tottime * 10);
	if (vl->enemies == vl->kills)
		score = score + 50000;
	if (vl->treasure == vl->tottreasure)
		score = score + 50000;
	if (vl->hp >= 100)
		score = score + 10000;
	if (vl->hp <= 0)
		score = score - 100000;
	if (vl->ammo >= 100)
		score = score + 10000;
	if (vl->tottime < 180)
		score = score + 50000;
	scor = ft_itoa(score);
	temp = ft_strjoin("Total Score ", scor);
	vl->mstat[6] = mlx_put_string(vl->mlx, temp, vl->w / 2 - 150, 430);
	ft_vafree(2, scor, temp);
	mlx_resize_image(vl->mstat[6], 300, 50);
	vl->mstat[7] = mlx_put_string(vl->mlx, "Press Jump to restart", vl->w / 2 - 200, 480);
	mlx_resize_image(vl->mstat[7], 400, 50);
}

void	ft_finish(t_varlist *vl)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	vl->oimg = mlx_new_image(vl->mlx, vl->w, vl->h);
	while (y < vl->h)
	{
		while (x < vl->w)
		{
			mlx_put_pixel(vl->oimg, x, y, 0x0000FF66);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_image_to_window(vl->mlx, vl->oimg, 0, 0);
	mlx_set_instance_depth(vl->oimg->instances, 15);
	vl->mstat = ft_calloc(4096, 8);
	vl->mstat[0] = mlx_put_string(vl->mlx, "YOU COMPLETED THE LEVEL!", vl->w / 2 - 250, 30);
	mlx_resize_image(vl->mstat[0], 500, 150);
	ft_printstats1(vl);
	ft_printstats2(vl);
	ft_printscore(vl);
	vl->menu = 1;
}

void	ft_youdied(t_varlist *vl)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	vl->oimg = mlx_new_image(vl->mlx, vl->w, vl->h);
	while (y < vl->h)
	{
		while (x < vl->w)
		{
			mlx_put_pixel(vl->oimg, x, y, 0xFF000066);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_image_to_window(vl->mlx, vl->oimg, 0, 0);
	mlx_set_instance_depth(vl->oimg->instances, 15);
	vl->mstat = ft_calloc(4096, 8);
	vl->mstat[0] = mlx_put_string(vl->mlx, "YOU DIED!", vl->w / 2 - 250, 30);
	mlx_resize_image(vl->mstat[0], 500, 150);
	ft_printstats1(vl);
	ft_printstats2(vl);
	ft_printscore(vl);
	vl->menu = 1;
}
