/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test5.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 02:54:36 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:15:07 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		ret;
	char	*s;
	char	*r;

	ret = 0;
	s = "Hallo dit is een string";
	r = ft_strdup(s);
	if (strncmp(r, s, 24) != 0)
		ret = 1;
	free (r);
	return (ret);
}
