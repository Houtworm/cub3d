/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test4.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 02:56:39 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:16:49 by houtworm      ########   odam.nl         */
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

	s = "iiooiooo";
	c = 'i';
	a = "iooo";
	if (strncmp(ft_strrchr(s, c), a, 10))
		return (1);
	return (0);
}
