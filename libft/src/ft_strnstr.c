/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 16:14:33 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 17:00:19 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	long unsigned int	ih;
	int					in;

	if (h == NULL || n == NULL)
		return (NULL);
	ih = 0;
	if (!*n)
		return ((char *)&h[ih]);
	while (h[ih] != '\0' && len > ih)
	{
		if (h[ih] == n[0])
		{
			in = 1;
			while (n[in] != '\0' && h[ih + in] == n[in] && (ih + in) < len)
				in++;
			if (n[in] == '\0')
				return ((char *)&h[ih]);
		}
		ih++;
	}
	return (NULL);
}
