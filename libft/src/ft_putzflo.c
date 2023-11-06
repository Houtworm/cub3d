/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putzflo.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 21:45:39 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 17:00:08 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putzflo(double n, int e)
{
	long long	i;
	long long	f;
	char		*t;

	i = n;
	f = ft_ftoi(n);
	t = ft_ltoa(f);
	if (ft_around(t, e))
		i++;
	ft_putnbr(i);
	i = 0;
	if (e > 0)
	{
		ft_putchar('.');
		while (e > i)
		{
			if (t[i] >= '0' && t[i] <= '9')
				ft_putchar(t[i]);
			else
				ft_putchar('0');
			i++;
		}
	}
	free (t);
}
