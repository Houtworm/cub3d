/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test11.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 03:07:54 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:09:41 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/libft.h"
#include <stdio.h>

int	main(void)
{
	int	c;

	c = '\0';
	if (ft_isprint(c))
		return (1);
	return (0);
}
