/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itooa.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/01 01:30:17 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 16:59:47 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_itooa(long double n)
{
	char				t[25];
	char				*r;
	unsigned long long	c;
	long double			tf;
	unsigned long long	ti;

	c = 0;
	while (n != 0)
	{
		if (n < 8)
			t[c] = n + '0';
		else if (n > 7)
		{
			tf = n / 8;
			ti = n / 8;
			tf = (tf - ti) * 8;
			t[c] = tf + '0';
		}
		ti = n / 8;
		n = ti;
		c++;
	}
	t[c] = '\0';
	r = ft_revstr(t);
	return (r);
}
