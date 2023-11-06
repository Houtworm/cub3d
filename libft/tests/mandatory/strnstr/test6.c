/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test6.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 02:40:21 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:16:47 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*h;
	char	*n;
	int		len;
	char	*a;

	h = "Joepiedepoepie";
	n = "Joep";
	len = 4;
	a = "Joepiedepoepie";
	if (strncmp(ft_strnstr(h, n, len), a, 15))
		return (1);
	return (0);
}
