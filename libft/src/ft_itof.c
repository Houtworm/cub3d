/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itof.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 22:18:50 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 16:59:35 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

double	ft_itof(int n)
{
	double	r;
	int		l;

	l = ft_intlen(n);
	r = n;
	while (l > 0)
	{
		r = r / 10;
		l--;
	}
	return (r);
}
