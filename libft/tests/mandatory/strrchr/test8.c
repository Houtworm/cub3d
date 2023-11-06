/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test8.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 02:56:39 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:16:51 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*s;
	int		c;
	char	*a;

	s = "hallo";
	c = 'l';
	a = "lo\0";
	if (memcmp(ft_strrchr(s, c), a, 3))
		return (1);
	return (0);
}
