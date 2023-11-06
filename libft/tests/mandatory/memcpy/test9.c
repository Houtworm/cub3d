/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test9.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 03:02:18 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:10:19 by houtworm      ########   odam.nl         */
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
	dst = NULL;
	src = malloc(8 * 7);
	strcpy(src, "123456");
	ft_memcpy(dst, src, 7);
	if (dst)
		r = 1;
	free (src);
	return (r);
}
