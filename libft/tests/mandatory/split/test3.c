/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test3.c                                            :+:    :+:            */
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
	char	*str2;
	char	*s5;
	char	*s6;
	char	**r2;
	int		r;

	r = 0;
	str2 = "split||th\0is|for|me|||||!|";
	s5 = "split";
	s6 = "th";
	r2 = ft_split(str2, '|');
	if (strncmp(r2[0], &s5[0], 50) || strncmp(r2[1], &s6[0], 50))
		r = 1;
	free(r2[0]);
	free(r2[1]);
	free(r2);
	return (r);
}
