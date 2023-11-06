/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test9.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 02:48:46 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:15:03 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		r;
	char	**temp;
	char	**r9;

	r = 0;
	temp = malloc(8 * 3);
	temp[0] = "split";
	temp[1] = "this";
	temp[2] = NULL;
	r9 = ft_split("split this", ' ');
	if (r9[2] != temp[2])
		r = 1;
	free(r9[0]);
	free(r9[1]);
	free(r9);
	free(temp);
	return (r);
}
