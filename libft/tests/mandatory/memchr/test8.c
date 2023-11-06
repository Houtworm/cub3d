/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test8.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 03:03:52 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:09:54 by houtworm      ########   odam.nl         */
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
	s = malloc(8 * 8);
	memcpy(s, "H\0he\0\0o", 7);
	p = ft_memchr(s, 'e', 4);
	if (memcmp(p, "e\0\0o", 4))
		r = 1;
	free(s);
	return (r);
}
