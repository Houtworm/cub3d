/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_frearr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/11 21:54:13 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 16:56:27 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_frearr(char **s)
{
	int		n;

	n = 0;
	while (s[n] != NULL)
		n++;
	while (n >= 0)
	{
		free(s[n]);
		n--;
	}
	free(s);
	return (NULL);
}
