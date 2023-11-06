/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cntchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <djonker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/11 17:23:36 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 16:56:12 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_cntchr(const char *str, char c, int s)
{
	int	i;
	int	t;

	i = 0;
	while (*str)
	{
		if (*str == c)
		{
			i++;
			str++;
		}
		t = s;
		while (t > 0)
		{
			str++;
			t--;
		}
	}
	return (i);
}
