/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test6.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 02:43:27 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:15:23 by houtworm      ########   odam.nl         */
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
	r = ft_strmapi(NULL, &ft_test_f);
	if (r)
		ret = 1;
	free (r);
	return (ret);
}
