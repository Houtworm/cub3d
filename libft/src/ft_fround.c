/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fround.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 07:42:16 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 16:56:28 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

double	ft_fround(double n, int h)
{
	char	*s;
	char	**t;
	char	*r;

	s = ft_ftoa(n);
	t = ft_split(s, '.');
	t[0][ft_intlen(n)] = '.';
	t[0][ft_intlen(n) + 1] = '\0';
	if (h == 0)
	{
		if (t[1][0] > '5')
			t[0][ft_intlen(n) - 1] = t[0][ft_intlen(n) - 1] + 1;
	}
	else if (t[1][h] > '5')
	{
		t[1][h - 1] = t[1][h - 1] + 1;
	}
	t[1][h] = '\0';
	r = ft_strjoin(t[0], t[1]);
	n = ft_atof(r);
	ft_frenarr(t, 2);
	free(r);
	free(s);
	return (n);
}
