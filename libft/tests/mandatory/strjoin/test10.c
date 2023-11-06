/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test10.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 02:53:16 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:15:08 by houtworm      ########   odam.nl         */
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
	r = ft_strjoin(NULL, NULL);
	if (r)
		ret = 1;
	return (ret);
}
