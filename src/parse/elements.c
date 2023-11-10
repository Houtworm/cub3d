/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   elements.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 17:33:50 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/10 08:45:58 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	ft_checkforbasics(t_varlist *vl, char element, int x, int y)
{
	if (ft_strchr(" 0", element))
		return ('0');
	else if (element == '1')
		return ('1');
	else if (ft_strchr("NESW", element))
		return (ft_initplayer(vl, element, y, x));
	else if (element == 'D')
		return ('0');
	else if (element == 'X')
		return ('4');
	return ('\0');
}

char	ft_checkfordecor(t_varlist *vl, char element, int x, int y)
{
	if (element == 'B')
		return (ft_addsoliddecor(vl, y, x, 0));
	else if (element == 'b')
		return (ft_addsoliddecor(vl, y, x, 1));
	else if (element == 'L')
		return (ft_addsoliddecor(vl, y, x, 2));
	else if (element == 'A')
		return (ft_addsoliddecor(vl, y, x, 3));
	else if (element == 'P')
		return (ft_addsoliddecor(vl, y, x, 4));
	else if (element == 'p')
		return (ft_addsoliddecor(vl, y, x, 5));
	else if (element == 'V')
		return (ft_addsoliddecor(vl, y, x, 6));
	else if (element == 'f')
		return (ft_addsoliddecor(vl, y, x, 7));
	else if (element == 'T')
		return (ft_addsoliddecor(vl, y, x, 8));
	else if (element == 's')
		return (ft_addsoliddecor(vl, y, x, 9));
	else if (element == 'l')
		return (ft_addwalktroughdecor(vl, y, x, 10));
	else if (element == 'C')
		return (ft_addwalktroughdecor(vl, y, x, 11));
	return ('\0');
}

char	ft_checkforpickup(t_varlist *vl, char element, int x, int y)
{
	if (element == '$')
		return (ft_addpickup(vl, y, x, 0));
	else if (element == '#')
		return (ft_addpickup(vl, y, x, 1));
	else if (element == '*')
		return (ft_addpickup(vl, y, x, 2));
	else if (element == '&')
		return (ft_addpickup(vl, y, x, 3));
	else if (element == '9')
		return (ft_addpickup(vl, y, x, 4));
	else if (element == '8')
		return (ft_addpickup(vl, y, x, 5));
	else if (element == '7')
		return (ft_addpickup(vl, y, x, 6));
	else if (element == '5')
		return (ft_addpickup(vl, y, x, 7));
	else if (element == '6')
		return (ft_addpickup(vl, y, x, 8));
	else if (element == '3')
		return (ft_addpickup(vl, y, x, 9));
	else if (element == '4')
		return (ft_addpickup(vl, y, x, 10));
	else if (element == '2')
		return (ft_addpickup(vl, y, x, 11));
	return ('\0');
}

char	ft_checkforenemy(t_varlist *vl, char element, int x, int y)
{
	if (element == 'K')
		return (ft_addenemy(vl, y, x, 0));
	return ('\0');
}

char	ft_checkmapelement(t_varlist *vl, char element, int x, int y)
{
	char	ret;

	ret = ft_checkforbasics(vl, element, x, y);
	if (!ret)
		ret = ft_checkforenemy(vl, element, x, y);
	if (!ret)
		ret = ft_checkfordecor(vl, element, x, y);
	if (!ret)
		ret = ft_checkforpickup(vl, element, x, y);
	if (ret)
		return (ret);
	ft_putchar(element);
	ft_putendl(" character found on map which makes it invalid");
	exit (1);
}
