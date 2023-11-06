/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cntwrds.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 20:37:04 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 16:56:13 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_cntwrds(char *s, char *c)
{
	int		iw;
	int		is;

	is = 0;
	iw = 0;
	while (s[is] != '\0')
	{
		if (ft_chrstr(s[is], c))
			while (ft_chrstr(s[is], c))
				is++;
		if (!(ft_chrstr(s[is], c)))
		{
			while (!(ft_chrstr(s[is], c)))
				is++;
			iw++;
		}
	}
	return (iw);
}
