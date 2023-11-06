/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test1.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 02:48:46 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:17:11 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		ret;
	char	*s0;
	char	*s4;
	char	**r;

	ret = 0;
	s0 = "split\0";
	s4 = "!\0";
	r = ft_split("split||this|for|me|||||!", '|');
	if (strncmp(r[0], &s0[0], 50) || strncmp(r[4], &s4[0], 50))
		ret = 1;
	free(r[0]);
	free(r[1]);
	free(r[2]);
	free(r[3]);
	free(r[4]);
	free(r[5]);
	free(r);
	return (ret);
}
