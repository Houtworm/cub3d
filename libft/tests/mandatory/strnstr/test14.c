/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test14.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 02:40:21 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:16:45 by houtworm      ########   odam.nl         */
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

	h = NULL;
	n = "piede";
	len = 20;
	if (ft_strnstr(h, n, len))
		return (1);
	return (0);
}
