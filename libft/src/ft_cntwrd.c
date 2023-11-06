/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cntwrd.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 20:37:04 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 16:56:13 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_cntwrd(char *s, char c)
{
	int		iw;
	int		is;

	is = 0;
	iw = 0;
	while (s[is] != '\0')
	{
		if (s[is] == c)
			while (s[is] == c)
				is++;
		if (s[is] != c && s[is] != '\0')
		{
			while (s[is] != c && s[is] != '\0')
				is++;
			iw++;
		}
	}
	return (iw);
}
