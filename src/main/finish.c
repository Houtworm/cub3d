/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   finish.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 14:13:07 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/09 00:54:39 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_printstats1(t_varlist *vl)
{
	char	*total;
	char	*current;
	char	*temp;

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
}

void	ft_printstats2(t_varlist *vl)
{
	char	*current;
	char	*temp;

	current = ft_itoa(vl->ammo);
	temp = ft_vastrjoin(2, "Ammo left: ", current);
	ft_putendl(temp);
	ft_vafree(2, temp, current);
	current = ft_itoa(vl->hp);
	temp = ft_vastrjoin(2, "HP left: ", current);
	ft_putendl(temp);
	ft_vafree(2, temp, current);
}

void	ft_printscore(t_varlist *vl)
{
	int		score;

	score = (vl->treasure * 10000) + (vl->kills * 1000);
	score = score + (vl->ammo * 100) + (vl->hp * 100);
	score = score - (vl->tottime * 10);
	if (vl->enemies == vl->kills)
		score = score + 50000;
	if (vl->treasure == vl->tottreasure)
		score = score + 50000;
	if (vl->hp >= 100)
		score = score + 10000;
	if (vl->ammo >= 100)
		score = score + 10000;
	if (vl->tottime < 180)
		score = score + 50000;
	ft_putstr("Total Score: ");
	ft_putnbr(score);
	ft_putendl("");
}

void	ft_finish(t_varlist *vl)
{
	ft_printstats1(vl);
	ft_printstats2(vl);
	ft_printscore(vl);
	mlx_close_window(vl->mlx);
	return ;
}
