/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test4.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 03:02:18 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:10:17 by houtworm      ########   odam.nl         */
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
	dst = malloc(8 * 21);
	src = malloc(8 * 7);
	strcpy(src, "123456");
	strcpy(dst, "abcdefghijklmnopqrst");
	ft_memcpy(dst, src, 10);
	if (strncmp(dst, "123456\0", 7))
		r = 1;
	free (dst);
	free (src);
	return (r);
}
