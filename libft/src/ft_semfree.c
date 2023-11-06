/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_semfree.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/17 20:09:41 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:00:12 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_semfree(char *file)
{
	int		fd;
	char	*content;
	int		number;

	fd = open(file, O_RDONLY);
	content = ft_calloc(2, 8);
	read(fd, content, 2);
	number = ft_atoi(content);
	free(content);
	close(fd);
	number++;
	fd = open(file, O_RDWR | O_TRUNC, 0777);
	ft_putnbr_fd(number, fd);
	close(fd);
	return (0);
}
