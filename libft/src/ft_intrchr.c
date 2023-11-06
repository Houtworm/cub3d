/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 16:14:50 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 16:59:15 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_intrchr(const char *s, int c)
{
	int		i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] != '\0')
		i++;
	i--;
	while (i >= 0 && s[i] != c)
		i--;
	return (i);
}
