/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test8.c                                            :+:    :+:            */
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
	dst = malloc(8 * 8);
	strcpy(dst, "abcdefg");
	ft_memcpy(dst, NULL, 7);
	if (!memcmp(dst, "abcdef", 6))
		r = 1;
	free (dst);
	return (r);
}
