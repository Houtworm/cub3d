/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test15.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <djonker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 22:31:27 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 17:09:00 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/libft.h"
#include <stdio.h>

int	main(void)
{
	char	*str;
	int		a;

	str = "-2147483649";
	a = 2147483647;
	if (ft_atoi(str) != a)
		return (1);
	return (0);
}
