/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test2.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 02:47:24 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:09:07 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		rtrn;
	char	*b;

	b = ft_calloc(3, 1);
	rtrn = 0;
	if (memcmp(b, "\0\0\0", 3))
		rtrn = 1;
	free(b);
	return (rtrn);
}
