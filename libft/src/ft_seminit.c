/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_seminit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/17 20:08:39 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:00:13 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_seminit(char *file, int number)
{
	int	fd;

	fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
	{
		ft_putendl_fd("initializing semaphore failed", 2);
		return (1);
	}
	ft_putnbr_fd(number, fd);
	close(fd);
	return (0);
}
