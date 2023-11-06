/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_frenarr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/11 21:54:13 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 16:56:27 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_frenarr(char **s, int n)
{
	while (n > 0)
	{
		n--;
		free(s[n]);
	}
	free(s);
	return (NULL);
}
