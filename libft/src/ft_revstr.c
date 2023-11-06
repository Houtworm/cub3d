/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_revstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 11:54:50 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 17:00:11 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_revstr(char *s)
{
	char	*r;
	int		is;
	int		ir;

	r = ft_calloc(8 * (ft_strlen(s) + 1), 1);
	is = ft_strlen(s) - 1;
	ir = 0;
	while (is >= 0)
	{
		r[ir] = s[is];
		ir++;
		is--;
	}
	r[ir] = '\0';
	s = r;
	return (r);
}
