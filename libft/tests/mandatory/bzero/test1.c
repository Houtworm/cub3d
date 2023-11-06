/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test1.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 02:31:08 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:09:05 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*s;
	int		n;

	s = NULL;
	n = 1;
	ft_bzero(s, n);
	if (!s)
		return (0);
	return (1);
}
