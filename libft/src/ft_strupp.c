/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strupp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 05:49:38 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 17:00:21 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strupp(char *s)
{
	char	*r;
	int		i;

	i = 0;
	r = ft_calloc(8 * (ft_strlen(s) + 1), 1);
	while (s[i])
	{
		r[i] = ft_toupper(s[i]);
		i++;
	}
	free(s);
	return (r);
}
