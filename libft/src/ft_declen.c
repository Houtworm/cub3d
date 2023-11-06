/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_declen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 04:29:09 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 16:56:15 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_declen(double n)
{
	double	f;
	int		i;
	int		l;

	i = n;
	f = n - i;
	l = 0;
	while (f != 0 && l < 10)
	{
		l++;
		n = n * 10;
		i = n;
		f = n - i;
	}
	return (l);
}
