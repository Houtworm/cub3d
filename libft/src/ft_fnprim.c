/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fnprim.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/01 04:42:24 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 16:56:26 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

unsigned long long	ft_fnprim(unsigned long long n)
{
	while (n < 1000000000000000000)
	{
		if (ft_isprim(n) == 1)
			return (n);
		n++;
	}
	return (0);
}
