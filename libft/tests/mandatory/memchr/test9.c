/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test9.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 03:03:52 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:10:10 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		r;
	char	*s;
	char	*p;

	r = 0;
	s = malloc(8 * 13);
	memcpy(s, "Hello\0\0hello", 12);
	p = ft_memchr(s, 'e', 10);
	if (memcmp(p, "ello\0\0h", 7))
		r = 1;
	free(s);
	return (r);
}
