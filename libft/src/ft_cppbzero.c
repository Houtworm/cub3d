/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cppbzero.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 12:17:56 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 16:56:14 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_cppbzero(char **cpp)
{
	int	i;

	i = 0;
	while (cpp[i])
	{
		ft_bzero(cpp[i], ft_strlen(cpp[i]));
		i++;
	}
}
