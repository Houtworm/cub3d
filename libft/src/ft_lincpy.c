/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lincpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/04 21:40:35 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 16:59:50 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_lincpy(char *dst, const char *src)
{
	char				*d;
	const char			*s;
	long unsigned int	i;

	i = 0;
	d = dst;
	s = src;
	if (dst != NULL || src != NULL)
	{
		while (s[i] != '\0' && s[i] != '\n')
		{
			d[i] = s[i];
			i++;
		}
		d[i] = '\0';
	}
	return (dst);
}
