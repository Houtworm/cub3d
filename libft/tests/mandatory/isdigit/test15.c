/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test15.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 03:06:47 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:09:36 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/libft.h"
#include <stdio.h>

int	main(void)
{
	int	c;

	c = 'z';
	if (ft_isdigit(c))
		return (1);
	return (0);
}
