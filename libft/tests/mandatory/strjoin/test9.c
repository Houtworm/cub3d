/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test9.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 02:53:16 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:15:10 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		ret;
	char	*r;

	ret = 0;
	r = ft_strjoin("Dit is een ", NULL);
	if (memcmp(r, "Dit is een \0", 12))
		ret = 1;
	free (r);
	return (ret);
}
