/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ldeclen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/25 11:30:37 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 16:59:48 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_ldeclen(long double n)
{
	long double	f;
	long long	i;
	int			l;

	i = n;
	f = n - i;
	l = 0;
	while (f != 0 && l < 50)
	{
		l++;
		n = n * 10;
		i = n;
		f = n - i;
	}
	return (l);
}
