/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test2.c                                            :+:    :+:            */
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
	int		r;
	char	**r6;

	r = 0;
	r6 = ft_split("abcdefghijklmnopqrstuvwxyz,.", ' ');
	if (strncmp(r6[0], "abcdefghijklmnopqrstuvwxyz,.", 50))
		r = 1;
	free(r6[0]);
	free(r6);
	return (r);
}
