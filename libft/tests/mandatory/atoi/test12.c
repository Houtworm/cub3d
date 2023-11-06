/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test12.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 02:01:57 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:08:59 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/libft.h"
#include <stdio.h>

int	main(void)
{
	char	*str;
	int		a;

	str = NULL;
	a = 0;
	if (ft_atoi(str) != a)
		return (1);
	return (0);
}
