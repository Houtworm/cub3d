/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoo.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/01 01:30:17 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 16:59:47 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

unsigned long long	ft_itoo(double n)
{
	char				r[20];
	unsigned long long	c;
	double				tf;
	unsigned long long	ti;

	c = 0;
	while (n != 0)
	{
		if (n < 8)
			r[c] = n + '0';
		else if (n > 7)
		{
			tf = n / 8;
			ti = n / 8;
			tf = (tf - ti) * 8;
			r[c] = tf + '0';
		}
		ti = n / 8;
		n = ti;
		c++;
	}
	r[c] = '\0';
	c = ft_atou(ft_revstr(r));
	return (c);
}
