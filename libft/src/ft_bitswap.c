/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bitswap.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <djonker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/17 06:29:44 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 16:55:44 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_bitswap(char *str)
{
	while (*str)
	{
		if (*str == '1')
			*str = '0';
		else if (*str == '0')
			*str = '1';
		str++;
	}
	return (str);
}
