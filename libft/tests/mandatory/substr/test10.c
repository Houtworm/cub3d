/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test10.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 02:36:13 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:16:56 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		ret;
	char	*r;

	ret = 0;
	r = ft_substr("stringstring", 3, 1);
	if (strncmp(r, "i", 2))
		ret = 1;
	free (r);
	return (ret);
}
