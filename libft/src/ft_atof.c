/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atof.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 05:48:34 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 16:55:42 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

double	ft_atof(char *str)
{
	int		i;
	double	f;
	char	**t;
	int		l;

	t = ft_split(str, '.');
	f = ft_atoi(t[1]);
	l = ft_intlen(f);
	i = ft_atoi(t[0]);
	while (l > 0)
	{
		f = f / 10;
		l--;
	}
	ft_frenarr(t, 2);
	return (i + f);
}
