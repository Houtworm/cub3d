/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_gethost.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 07:45:51 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 16:59:03 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_gethost(void)
{
	int		fd;
	char	*line;
	char	*host;

	fd = open("/etc/hostname", O_RDONLY);
	get_next_line(fd, &line);
	host = ft_strdup(line);
	free(line);
	close(fd);
	return (host);
}
