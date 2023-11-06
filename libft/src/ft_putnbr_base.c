/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <djonker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/04 06:48:59 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 17:00:05 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr_base(unsigned long long number, int base)
{
	if (number >= (unsigned long long)base)
		ft_putnbr_base(number / base, base);
	number %= base;
	if (number >= 10)
		number = number + 87;
	else
		number = number + 48;
	ft_putchar(number);
}
