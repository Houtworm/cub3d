/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test9.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 03:00:42 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:10:23 by houtworm      ########   odam.nl         */
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
	dst = malloc(8 * 6);
	src = malloc(8 * 6);
	strcpy(dst, "Olleh");
	memcpy(src, "He\0\0o", 5);
	ft_memmove(dst, src, 5);
	if (memcmp(dst, "He\0\0o", 5))
		r = 1;
	free (dst);
	free (src);
	return (r);
}
