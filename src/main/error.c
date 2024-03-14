/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 17:13:58 by houtworm      #+#    #+#                 */
/*   Updated: 2024/03/14 17:16:42 by djonker          ###   ########.fr       */
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
