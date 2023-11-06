/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lftoa.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/25 11:38:35 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 16:59:49 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memsetfrom(void *s, int c, size_t n, int from)
{
	char				*p;

	p = s;
	while (from > 0 && *p)
	{
		p++;
		from--;
	}
	while (n > 0 && *p)
	{
		*p = c;
		p++;
		n--;
	}
	return (s);
}

char	*ft_lftoa(long double n)
{
	char		*ti;
	char		*tf;
	char		*rr;
	int			i;

	rr = ft_ltoa(n);
	ti = ft_strjoin(rr, ".");
	free(rr);
	tf = ft_dtoa(n);
	rr = ft_strjoin(ti, tf);
	free(ti);
	free(tf);
	ft_memsetfrom(rr, '\0', ft_strlen(rr), 23);
	return (rr);
}
