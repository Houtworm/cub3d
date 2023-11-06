/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test11.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 02:37:38 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:16:51 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		ret;
	char	*s1;
	char	*set;
	char	*a;
	char	*r;

	ret = 0;
	r = ft_strtrim("Hallo dit is een str\ting", "str\ting");
	if (strncmp(r, "Hallo dit is een \0", 18))
		ret = 1;
	free (r);
	return (ret);
}
