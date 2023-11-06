/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 17:13:58 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/05 04:42:25 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_errorexit(char *reason, char *function, int code)
{
	ft_putstr("Error: ");
	ft_putstr(reason);
	ft_putendl(function);
	exit(code);
}
