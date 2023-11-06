/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 17:33:50 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/05 18:50:53 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	ft_addwalktroughdecor(t_varlist *vl, int x, int y, int number)
{
	vl->sprite[vl->spritecount].x = x + 0.5;
	vl->sprite[vl->spritecount].y = y + 0.5;
	vl->sprite[vl->spritecount].number = number;
	vl->sprite[vl->spritecount].type = 1;
	vl->spritecount++;
	return ('0');
}

char	ft_addsoliddecor(t_varlist *vl, int x, int y, int number)
{
	vl->sprite[vl->spritecount].x = x + 0.5;
	vl->sprite[vl->spritecount].y = y + 0.5;
	vl->sprite[vl->spritecount].number = number;
	vl->sprite[vl->spritecount].type = 1;
	vl->spritecount++;
	return ('2');
}

char	ft_addpickup(t_varlist *vl, int x, int y, int number)
{
	vl->sprite[vl->spritecount].x = x + 0.5;
	vl->sprite[vl->spritecount].y = y + 0.5;
	vl->sprite[vl->spritecount].number = number;
	vl->sprite[vl->spritecount].type = 2;
	if (number < 4)
		vl->tottreasure++;
	vl->spritecount++;
	return ('0');
}

char	ft_addenemy(t_varlist *vl, int x, int y, int number)
{
	vl->sprite[vl->spritecount].x = x + 0.5;
	vl->sprite[vl->spritecount].y = y + 0.5;
	vl->sprite[vl->spritecount].number = number;
	vl->sprite[vl->spritecount].type = 3;
	vl->enemies++;
	vl->spritecount++;
	return ('2');
}
