/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test1.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 02:43:27 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:15:21 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/libft.h"
#include <stdio.h>
#include <string.h>

char	ft_test_f(unsigned int i, char c)
{
	i = 0;
	c = 'a';
	i = i + c;
	return ('a');
}

int	main(void)
{
	int		ret;
	char	*r;

	ret = 0;
	r = ft_strmapi("Dit", &ft_test_f);
	if (strncmp(r, "aaa", 10))
		ret = 1;
	free (r);
	return (ret);
}
