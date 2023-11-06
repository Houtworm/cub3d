/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test3.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 02:43:27 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:15:22 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/libft.h"
#include <stdio.h>
#include <string.h>

char	ft_test_f(unsigned int i, char c)
{
	i++;
	c = ft_tolower(c);
	return (c);
}

int	main(void)
{
	int		ret;
	char	*r;

	ret = 0;
	r = ft_strmapi("Dit", &ft_test_f);
	if (strncmp(r, "dit", 10))
		ret = 1;
	free (r);
	return (ret);
}
