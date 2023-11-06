/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itob.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/04 04:42:54 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 16:59:33 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_itob(int d)
{
	char	s[20];
	int		i;
	char	*r;

	i = 0;
	while (d != 0)
	{
		s[i] = d % 2 + '0';
		d = d / 2;
		i++;
	}
	s[i] = '\0';
	r = ft_revstr(s);
	i = ft_atoi(r);
	free(r);
	return (i);
}
