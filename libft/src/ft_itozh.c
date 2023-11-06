/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itozh.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 03:00:29 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 16:59:48 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_itozh(double n, int z)
{
	char	*s;
	int		l;
	int		i;
	char	*r;

	r = ft_calloc(z + 1, 1);
	i = 0;
	s = ft_itoh(n);
	l = ft_strlen(s);
	while (l < z)
	{
		r[i] = '0';
		l++;
		i++;
	}
	l = 0;
	while (l < z)
	{
		r[i] = s[l];
		i++;
		l++;
	}
	ft_strlcpy(s, (const char *)r, (size_t)z + 1);
	free (r);
	return (s);
}
