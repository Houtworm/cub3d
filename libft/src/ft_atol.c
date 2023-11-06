/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atol.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 19:08:11 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 16:55:43 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

long long	ft_atol(char *str)
{
	unsigned long long	r;
	int					c;
	int					n;

	r = 0;
	c = 0;
	n = 1;
	while ((str[c] == 32) || (str[c] > 8 && str[c] < 14))
		c++;
	if (str[c] == '-' || str[c] == '+')
	{
		if (str[c] == '-')
			n = -1;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		r = 10 * r + (str[c] - '0');
		if (r > 9223372036854775807 && n == 1)
			return (-1);
		else if (r > 9223372036854775807 && n == -1)
			return (0);
		c++;
	}
	return (n * r);
}
