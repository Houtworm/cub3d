/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isallbyte.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 01:43:42 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 16:59:16 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isallbyte(char *str, char byte)
{
	if (!str)
		return (1);
	while (*str == byte)
		str++;
	if (!*str)
		return (1);
	return (0);
}
