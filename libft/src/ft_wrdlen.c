/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_wrdlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/22 12:00:13 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 17:00:27 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_wrdlen(char *s, char c, int i)
{
	int	r;
	int	w;
	int	is;

	r = 0;
	w = 0;
	is = 0;
	while (s[is] != '\0')
	{
		while (s[is] == c)
			is++;
		if (s[is] != c && s[is] != '\0')
		{
			r = 0;
			while (s[is] != c && s[is] != '\0')
			{
				is++;
				r++;
			}
			if (w == i)
				return (r);
			w++;
		}
	}
	return (0);
}
