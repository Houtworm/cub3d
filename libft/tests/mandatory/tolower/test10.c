/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test10.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 02:35:02 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:17:00 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/libft.h"
#include <stdio.h>

int	main(void)
{
	int	c;

	c = '[';
	if (ft_tolower(c) != '[')
		return (1);
	return (0);
}
