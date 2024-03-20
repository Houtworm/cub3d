/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 09:00:38 by djonker       #+#    #+#                 */
/*   Updated: 2024/03/20 04:40:54 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*p;

	i = ft_strlen((char *)s) + 1;
	p = malloc(i);
	if (p == NULL)
		return (p);
	ft_memcpy(p, s, i);
	return (p);
}
