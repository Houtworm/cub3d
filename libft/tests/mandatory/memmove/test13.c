/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test13.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 03:00:42 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:10:20 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		r;
	char	*dst;

	r = 0;
	dst = malloc(8 * 6);
	strcpy(dst, "Olleh");
	ft_memmove(dst, NULL, 1);
	if (strncmp(dst, "Olleh", 6))
		r = 1;
	free (dst);
	return (r);
}
