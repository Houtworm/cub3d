/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 17:33:50 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/10 08:54:40 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_northeast(t_varlist *vl, char dir)
{
	if (dir == 'N')
	{
		vl->dirx = -1;
		vl->diry = 0;
		vl->planex = 0;
		vl->planey = 0.66;
	}
	else if (dir == 'E')
	{
		vl->dirx = 0;
		vl->diry = 1;
		vl->planex = 0.66;
		vl->planey = 0;
	}
}

void	ft_southwest(t_varlist *vl, char dir)
{
	if (dir == 'S')
	{
		vl->dirx = 1;
		vl->diry = 0;
		vl->planex = 0;
		vl->planey = -0.66;
	}
	else if (dir == 'W')
	{
		vl->dirx = 0;
		vl->diry = -1;
		vl->planex = -0.66;
		vl->planey = 0;
	}
}

char	ft_initplayer(t_varlist *vl, char dir, int x, int y)
{
	vl->posx = x + 0.5;
	vl->posy = y + 0.5;
	if (dir == 'N' || dir == 'E')
		ft_northeast(vl, dir);
	if (dir == 'S' || dir == 'W')
		ft_southwest(vl, dir);
	return ('0');
}
