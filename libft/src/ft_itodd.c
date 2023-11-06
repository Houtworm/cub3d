/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itodd.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 03:00:29 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 16:59:34 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_itodd(double n)
{
	char	r[20];
	int		c;
	double	tf;
	int		ti;
	char	*s;

	c = 0;
	while (n != 0)
	{
		if (n < 12)
			r[c] = ft_htod(n);
		else if (n > 11)
		{
			tf = n / 12;
			ti = n / 12;
			tf = (tf - ti) * 12;
			r[c] = ft_htod(tf);
		}
		ti = n / 12;
		n = ti;
		c++;
	}
	r[c] = '\0';
	s = ft_revstr(r);
	return (s);
}
