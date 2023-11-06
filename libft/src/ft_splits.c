/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_splits.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 02:21:52 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 17:00:14 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**ft_splits(char *s, char *c)
{
	char	**r;
	int		iw;

	if (!s)
		return (NULL);
	iw = 0;
	r = ft_calloc(sizeof(r) * (ft_cntwrds(s, c) + 1), 1);
	if (!r)
		return (NULL);
	while (ft_cntwrds(s, c) > 0)
	{
		while (ft_chrstr(*s, c))
			s++;
		r[iw] = ft_malstrs((char *)s, c);
		if (r[iw] == NULL)
			return (ft_frenarr(r, iw));
		while (!(ft_chrstr(*s, c)) && *s != '\0')
			s++;
		iw++;
	}
	return (r);
}
