/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 08:35:56 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 16:59:58 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*p;
	unsigned char		t;

	if (!s)
		return (NULL);
	t = (unsigned char)c;
	p = (unsigned char *)s;
	while (n > 0)
	{
		if (t == *p)
			return ((void *)p);
		n--;
		++p;
	}
	return (NULL);
}
