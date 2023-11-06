/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test7.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 02:56:39 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:16:50 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*s;
	int		c;
	char	*a;

	s = "hall\0o";
	c = '\0';
	a = ft_strrchr("hall\0o", c);
	if (a)
		return (1);
	return (0);
}
