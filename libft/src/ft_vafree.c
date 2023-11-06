/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vafree.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 16:17:34 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 17:00:25 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

void	ft_vafree(int n, ...)
{
	int		i;
	va_list	va;
	void	*temp;

	va_start(va, n);
	i = 0;
	while (i < n)
	{
		temp = va_arg(va, void *);
		free(temp);
		i++;
	}
	va_end(va);
}
