/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_flolen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 04:00:01 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 16:56:26 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_flolen(double n)
{
	int	l;

	l = 1;
	l = l + ft_declen(n);
	l = l + ft_intlen(n);
	return (l);
}
