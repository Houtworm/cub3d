/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dtoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 03:46:17 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 16:56:16 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_dtoa(long double n)
{
	char		p[100];
	long double	temp;
	long long	i;
	char		*t;
	char		*f;

	i = n;
	temp = (long double)n - (long double)i;
	i = 0;
	while (temp * 10 < 1 && i < 49)
	{
		temp = temp * 10;
		p[i] = '0';
		i++;
	}
	p[i] = '\0';
	i = ft_lftoi(n);
	t = ft_ltoa(i);
	f = ft_strjoin(p, t);
	free(t);
	return (f);
}
