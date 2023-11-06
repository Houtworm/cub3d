/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test2.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <djonker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 22:32:56 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 17:09:02 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/libft.h"
#include <stdio.h>

int	main(void)
{
	char	*str;
	int		a;

	str = "-2147483648";
	a = -2147483648;
	if (ft_atoi(str) != a)
		return (1);
	return (0);
}
