/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test3.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 03:03:52 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:09:52 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		r;
	char	*s;
	char	*p;

	r = 0;
	s = malloc(8 * 6);
	strcpy(s, "Hello");
	p = ft_memchr(s, 'o', 5);
	if (strncmp(p, "o", 2))
		r = 1;
	free(s);
	return (r);
}
