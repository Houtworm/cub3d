/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test6.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 02:48:46 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:15:02 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		r;
	char	**r5;

	r = 0;
	r5 = ft_split("split   thi\tis", ' ');
	if (strncmp(r5[0], "split\0", 6) || strncmp(r5[1], "thi\tis\0", 7))
		r = 1;
	free(r5[0]);
	free(r5[1]);
	free(r5);
	return (r);
}
