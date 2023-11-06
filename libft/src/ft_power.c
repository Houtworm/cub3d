/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_power.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 01:18:37 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 17:00:02 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_power(int n, int p)
{
	int	r;

	if (p < 0)
		return (0);
	if (p == 0)
		return (1);
	else
		r = n * ft_power(n, p - 1);
	return (r);
}
