/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putull.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 04:22:10 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 17:00:08 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putull(unsigned long long n)
{
	if (n >= 10)
	{
		ft_putull(n / 10);
		ft_putull(n % 10);
	}
	else
		ft_putchar(n + '0');
}
