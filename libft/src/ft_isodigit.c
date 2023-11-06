/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isodigit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/06 17:19:46 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 16:59:22 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isodigit(int n)
{
	char	*s;

	s = ft_itoa(n);
	while (*s != '\0')
	{
		if (*s >= '0' && *s <= '7')
			s++;
		else
		{
			free(s);
			return (0);
		}
	}
	free(s);
	return (1);
}
