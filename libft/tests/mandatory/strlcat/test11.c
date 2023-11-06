/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test11.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 02:52:27 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:15:11 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		ret;
	char	*dst;

	ret = 0;
	dst = NULL;
	ft_strlcat(dst, NULL, 12);
	if (dst)
		ret = 1;
	return (ret);
}
