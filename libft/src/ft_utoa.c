/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 23:20:24 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 17:00:24 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_utoa(unsigned long long n)
{
	char		*r;
	int			l;

	l = ft_intlen(n) - 1;
	r = ft_calloc(l + 2, 1);
	if (r == NULL)
		return (NULL);
	while (n > 9 || n < 0)
	{
		if (n >= 10)
		{
			r[l] = n % 10 + '0';
			l--;
			n = (n / 10);
		}
	}
	r[l] = n + '0';
	return (r);
}
