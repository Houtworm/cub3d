/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test8.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 02:59:35 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:10:26 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		r;
	char	*s;

	r = 0;
	s = malloc(8 * 6);
	strcpy(s, "Hallo");
	ft_memset(s, '*', 0);
	if (strncmp(s, "Hallo", 6))
		r = 1;
	free (s);
	return (r);
}
