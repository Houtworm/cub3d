/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test3.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 02:31:08 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:09:06 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*s;
	int		n;
	char	*a;

	s = "Hallo";
	a = "Hallo";
	n = 0;
	ft_bzero(s, n);
	if (strncmp(s, a, 6))
		return (1);
	return (0);
}
