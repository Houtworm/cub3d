/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test13.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 02:51:24 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:15:15 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		r;
	char	*dst;

	r = 0;
	dst = NULL;
	ft_strlcpy(dst, "Hallo", 6);
	if (dst)
		r = 1;
	free (dst);
	return (r);
}
