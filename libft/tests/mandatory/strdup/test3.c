/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test3.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 02:54:36 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:15:06 by houtworm      ########   odam.nl         */
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
	s = "Hallo\tdit\tis\teen\tstring";
	r = ft_strdup(s);
	if (strncmp(r, s, 23) != 0)
		ret = 1;
	free (r);
	return (ret);
}
