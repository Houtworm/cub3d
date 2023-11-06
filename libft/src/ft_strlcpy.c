/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 08:22:27 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 17:00:17 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		i;

	if (dst == NULL || src == NULL)
		return (0);
	i = ft_strlen((char *)src);
	if (i + 1 < dstsize)
		ft_memcpy(dst, src, i + 1);
	else if (i != 0 && dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (i);
}
