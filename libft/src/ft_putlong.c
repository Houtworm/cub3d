/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putlong.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 04:22:10 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 17:00:05 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putlong(long long n)
{
	if (n < -9223372036854775807)
		return (ft_putstr("-9223372036854775808"));
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n >= 10)
	{
		ft_putlong(n / 10);
		ft_putlong(n % 10);
	}
	else
		ft_putchar(n + '0');
}
