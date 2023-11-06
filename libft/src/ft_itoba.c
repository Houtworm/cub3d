/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoba.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/04 04:42:54 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 16:59:29 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_itoba(unsigned long long d, size_t e)
{
	char	s[65];
	int		i;
	size_t	j;
	char	*r;

	i = 0;
	while (d != 0)
	{
		s[i] = d % 2 + '0';
		d = d / 2;
		i++;
	}
	s[i] = '\0';
	j = ft_strlen(s);
	while (e > j)
	{
		s[i] = '0';
		i++;
		j++;
	}
	s[i] = '\0';
	r = ft_revstr(s);
	return (r);
}
