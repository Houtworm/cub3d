/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_factor.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/01 04:03:20 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 16:56:25 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

unsigned long long	ft_factor(unsigned long long n)
{
	unsigned long long	r;

	r = 1;
	if (!(n >= 1 && n <= 20))
		return (0);
	if (n > 1)
		r = n * ft_factor(n - 1);
	return (r);
}
