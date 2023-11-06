/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 04:00:47 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 17:00:03 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putendl(char *s)
{
	if (!s)
		return ((void) NULL);
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}
