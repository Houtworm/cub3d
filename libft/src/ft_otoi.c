/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_otoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 16:54:01 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 17:00:01 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_otoi(int i)
{
	char	*s;
	int		is;
	int		ir;
	int		r;

	is = ft_intlen(i) - 1;
	ir = 0;
	r = 0;
	s = ft_itoa(i);
	while (s[is] != '\0')
	{
		r = r + (s[is] - '0') * ft_power(8, ir);
		is--;
		ir++;
	}
	free(s);
	return (r);
}
