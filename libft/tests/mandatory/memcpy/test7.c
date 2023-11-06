/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test7.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 03:02:18 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:10:18 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		r;
	char	*dst;
	char	*src;

	r = 0;
	dst = malloc(8 * 7);
	src = malloc(8 * 7);
	memcpy(src, "ab\0\0ef", 6);
	strcpy(dst, "123456");
	ft_memcpy(dst, src, 6);
	if (memcmp(dst, "ab\0\0ef", 6))
		r = 1;
	free (dst);
	free (src);
	return (r);
}
