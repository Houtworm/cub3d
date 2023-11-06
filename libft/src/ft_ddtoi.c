/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ddtoi.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 01:24:28 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 16:56:15 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_ddtoi(char *str)
{
	int		r;
	int		p;

	r = 0;
	p = ft_strlen(str) - 1;
	while (p >= 0)
	{
		if (*str >= '0' && *str <= '9')
			r = r + (*str - '0') * ft_power(12, p);
		else if ((*str >= 'a' && *str <= 'b') || (*str >= 'A' && *str <= 'B'))
			r = r + ft_dtoh(*str) * ft_power(12, p);
		else
			return (-0);
		str++;
		p--;
	}
	return (r);
}
