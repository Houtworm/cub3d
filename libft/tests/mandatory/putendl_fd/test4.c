/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test4.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 02:58:12 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:10:39 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/libft.h"
#include <stdio.h>

int	main(void)
{
	int		i;
	int		j;
	char	*stri;

	i = 0;
	stri = malloc(8 * 1000000);
	while (i < 999999)
	{
		stri[i] = 'a';
		i++;
	}
	ft_putendl_fd(stri, 1);
	free (stri);
	return (0);
}
