/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   finish.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 14:13:07 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/08 06:26:59 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_finish(t_varlist *vl)
{
	char	*total;
	char	*current;
	char	*temp;
	int		score;

	ft_putendl("You Won!");
	current = ft_itoa(vl->tottime);
	temp = ft_vastrjoin(3, "Time: ", current, " Seconds");
	ft_putendl(temp);
	ft_vafree(2, current, temp);
	total = ft_itoa(vl->enemies);
	current = ft_itoa(vl->kills);
	temp = ft_vastrjoin(4, "Nazis Killed: ", current, "/", total);
	ft_putendl(temp);
	ft_vafree(3, temp, total, current);
	total = ft_itoa(vl->tottreasure);
	current = ft_itoa(vl->treasure);
	temp = ft_vastrjoin(4, "Treasure found: ", current, "/", total);
	ft_putendl(temp);
	ft_vafree(3, temp, total, current);
	current = ft_itoa(vl->ammo);
	temp = ft_vastrjoin(2, "Ammo left: ", current);
	ft_putendl(temp);
	ft_vafree(2, temp, current);
	current = ft_itoa(vl->hp);
	temp = ft_vastrjoin(2, "HP left: ", current);
	ft_putendl(temp);
	ft_vafree(2, temp, current);
	ft_putstr("Total Score: ");
	score = vl->treasure * 1000 + vl->kills * 100;
	score = score + vl->ammo * 100 + vl->hp * 100;
	score = score - vl->tottime * 10;
	if (vl->enemies == vl->kills)
		score = score + 10000;
	if (vl->treasure == vl->tottreasure)
		score = score + 10000;
	ft_putnbr(score);
	ft_putendl("");
	mlx_close_window(vl->mlx);
	return ;
}
