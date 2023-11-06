/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_semwait.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/17 20:09:16 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:00:13 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_semwait(char *file)
{
	int		fd;
	char	*content;
	int		number;

	number = 0;
	while (number == 0)
	{
		fd = open(file, O_RDONLY);
		content = ft_calloc(2, 8);
		read(fd, content, 2);
		number = ft_atoi(content);
		free(content);
		close(fd);
	}
	number--;
	fd = open(file, O_RDWR | O_TRUNC, 0777);
	ft_putnbr_fd(number, fd);
	close(fd);
	return (0);
}
