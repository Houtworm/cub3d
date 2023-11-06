/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test17.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 02:37:38 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:16:53 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		ret;
	char	*s1;
	char	*set;
	char	*a;
	char	*r;

	ret = 0;
	r = ft_strtrim(NULL, NULL);
	if (r)
		ret = 1;
	free (r);
	return (ret);
}
