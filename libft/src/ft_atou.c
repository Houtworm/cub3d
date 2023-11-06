/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atou.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 19:08:11 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 16:55:43 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

unsigned long long	ft_atou(char *str)
{
	unsigned long long	r;
	int					c;

	r = 0;
	c = 0;
	while ((str[c] == 32) || (str[c] > 8 && str[c] < 14))
		c++;
	while (str[c] >= '0' && str[c] <= '9')
	{
		r = 10 * r + (str[c] - '0');
		c++;
	}
	free (str);
	return (r);
}
