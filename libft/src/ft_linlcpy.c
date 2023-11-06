/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_linlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/04 21:40:35 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 16:59:50 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_linlcpy(char *dst, const char *src, size_t n)
{
	char				*d;
	const char			*s;
	long unsigned int	i;

	i = 0;
	d = dst;
	s = src;
	if (dst != NULL || src != NULL)
	{
		while (s[i] != '\0' && s[i] != '\n' && n > 0)
		{
			d[i] = s[i];
			i++;
			n--;
		}
		d[i] = '\0';
	}
	return (dst);
}
