/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lftoi.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/25 11:30:20 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 16:59:49 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

long long	ft_lftoi(long double n)
{
	long long	r;
	long long	l;
	long double	f;

	if (ft_islneg(n))
		n = n * -1;
	l = ft_ldeclen(n);
	r = n;
	f = n - r;
	while (l > 0 && f * 10 < 9223372036854775807)
	{
		f = f * 10;
		l--;
	}
	r = f;
	return (r);
}
