/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test13.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 03:03:00 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:10:11 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/libft.h"
#include <stdio.h>

int	main(void)
{
	if (!ft_memcmp("HelloHello", "Hello", 8))
		return (1);
	return (0);
}
