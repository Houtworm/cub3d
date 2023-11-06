/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atodec.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 05:48:34 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 16:55:41 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

long double	ft_atodec(char *str)
{
	long double	f;
	int			l;

	f = ft_atoi(str);
	l = ft_intlen(f);
	while (l > 0)
	{
		f = f / 10;
		l--;
	}
	return (f);
}
