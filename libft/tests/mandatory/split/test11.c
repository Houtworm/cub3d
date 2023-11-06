/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test11.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 02:48:46 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:17:09 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		r;
	char	*str4;
	char	*s9;
	char	*s10;
	char	**r4;

	r = 0;
	str4 = "||splitth is";
	s9 = "splitth is";
	r4 = ft_split(str4, '|');
	if (strncmp(r4[0], &s9[0], 50))
		r = 1;
	free(r4[0]);
	free(r4);
	return (r);
}
