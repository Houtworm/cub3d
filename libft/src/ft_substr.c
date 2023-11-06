/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 15:52:16 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 17:00:21 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*r;
	long unsigned int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (len > ft_strlen((char *)s) && start < ft_strlen((char *)s))
		len = ft_strlen((char *)s) - start;
	r = ft_calloc(len + 1, 1);
	if (r == NULL)
		return (NULL);
	if (start >= ft_strlen((char *)s))
	{
		r[i] = '\0';
		return (r);
	}
	while (len > i)
	{
		r[i] = s[i + start];
		i++;
	}
	return (r);
}
