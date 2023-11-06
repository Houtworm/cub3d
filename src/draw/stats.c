/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stats.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 14:13:07 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/06 01:17:31 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_printgamestats(t_varlist *vl)
{
	char	*total;
	char	*current;
	char	*temp;

	current = ft_itoa(1 / vl->frametime);
	temp = ft_strjoin(current, " FPS");
	vl->fstat = mlx_put_string(vl->mlx, temp, 10, 10);
	ft_vafree(2, temp, current);
	total = ft_itoa(vl->enemies);
	current = ft_itoa(vl->kills);
	temp = ft_vastrjoin(4, "Kills: ", current, "/", total);
	vl->cstat = mlx_put_string(vl->mlx, temp, 10, 30);
	ft_vafree(3, temp, total, current);
	total = ft_itoa(vl->tottreasure);
	current = ft_itoa(vl->treasure);
	temp = ft_vastrjoin(4, "Treasure: ", current, "/", total);
	vl->kstat = mlx_put_string(vl->mlx, temp, 10, 50);
	ft_vafree(3, temp, total, current);
	mlx_set_instance_depth(vl->fstat->instances, 2);
	mlx_set_instance_depth(vl->cstat->instances, 3);
	mlx_set_instance_depth(vl->kstat->instances, 4);
}

void	ft_printplayerstats(t_varlist *vl)
{
	char	*current;
	char	*temp;

	current = ft_itoa(vl->ammo);
	temp = ft_vastrjoin(2, "Ammo: ", current);
	vl->astat = mlx_put_string(vl->mlx, temp, 10, vl->h - 30);
	ft_vafree(2, temp, current);
	current = ft_itoa(vl->hp);
	temp = ft_vastrjoin(2, "HP: ", current);
	vl->hstat = mlx_put_string(vl->mlx, temp, 10, vl->h - 50);
	ft_vafree(2, temp, current);
	mlx_set_instance_depth(vl->astat->instances, 6);
	mlx_set_instance_depth(vl->hstat->instances, 7);
}

void	ft_printstats(t_varlist *vl)
{
	ft_printgamestats(vl);
	ft_printplayerstats(vl);
}
