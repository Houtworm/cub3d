/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test6.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 02:38:36 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:15:05 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*str;

	str = ft_strchr("hallo\0aapje", '\0');
	if (memcmp(str, "\0", 1))
		return (1);
	return (0);
}
