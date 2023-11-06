/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test8.c                                            :+:    :+:            */
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
	char	**r8;

	r = 0;
	r8 = ft_split("hallo\0 alles goed?", '\0');
	temp = malloc(sizeof(char *));
	temp[0] = "hallo\0";
	if (strncmp(r8[0], temp[0], 6))
		r = 1;
	free(r8[0]);
	free(r8);
	free(temp);
	return (r);
}
