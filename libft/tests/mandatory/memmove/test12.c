/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test12.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 03:00:42 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:10:20 by houtworm      ########   odam.nl         */
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

	dst = NULL;
	r = 0;
	ft_memmove(dst, "Hello", 5);
	if (dst)
		r = 1;
	return (r);
}
