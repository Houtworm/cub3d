/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 21:20:32 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/25 05:52:55 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	i;
	char	*t;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	p = malloc(count * size);
	if (p == NULL)
		exit(1);
	if (p)
	{
		t = p;
		i = 0;
		while (count * size > i)
		{
			t[i] = '\0';
			i++;
		}
	}
	return (p);
}
