/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprim.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/01 04:32:30 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 16:59:23 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isprim(unsigned long long n)
{
	unsigned long long	c;
	unsigned long long	d;

	if (n < 2)
		return (0);
	c = 2;
	while (c <= n / 2)
	{
		d = 1;
		while (d <= n / 2)
		{
			if (c * d == n)
				return (0);
			d++;
		}
		c++;
	}
	return (1);
}
