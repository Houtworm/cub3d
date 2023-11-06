/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_luilen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 02:04:46 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 16:59:56 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_luilen(unsigned long long n)
{
	int	l;

	l = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10 + (l * 0);
		l++;
	}
	return (l);
}
