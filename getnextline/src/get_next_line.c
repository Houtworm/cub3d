/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 18:52:17 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/26 18:52:18 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

int	findnewline(struct s_gnl *strct)
{
	int	l;

	l = 0;
	while (strct->b[l] != '\0')
	{
		if (strct->b[l] == '\n')
			return (l + 1);
		l++;
	}
	return (-1);
}

int	newline(struct s_gnl *strct, char **line)
{
	int		l;
	char	*t;

	l = findnewline(strct);
	line[0] = gnl_substr((const char *)strct->b, 0, l - 1);
	if (line[0] == NULL)
		return (-1);
	t = gnl_substr((const char *)strct->b, l, BUFFER_SIZE - l);
	if (t == NULL)
	{
		free(line[0]);
		return (-1);
	}
	gnl_memcpy(strct->b, t, gnl_strlen(t));
	gnl_bzero(&strct->b[gnl_strlen(t)], BUFFER_SIZE - gnl_strlen(t));
	free(t);
	return (1);
}

int	blimit(int l, struct s_gnl *strct, char **line, char *t)
{
	char	*f;

	l = get_next_line(strct->fd, line);
	if (l == 1 || l == 0)
	{
		f = line[0];
		line[0] = gnl_strjoin(t, line[0]);
		free (f);
	}
	free(t);
	if (line[0] == NULL)
		return (-1);
	return (l);
}

int	nonewline(int l, struct s_gnl *strct, char **line)
{
	char	*t;

	t = gnl_substr((const char *)strct->b, 0, gnl_strlen(strct->b));
	gnl_bzero(&strct->b[0], BUFFER_SIZE);
	l = read(strct->fd, strct->b, BUFFER_SIZE);
	if (l == -1 || t == NULL)
	{
		line[0] = NULL;
		return (-1);
	}
	if (l == BUFFER_SIZE || findnewline(strct) > -1)
		return (blimit(l, strct, line, t));
	line[0] = gnl_strjoin(t, strct->b);
	gnl_bzero(&strct->b, BUFFER_SIZE);
	free(t);
	if (line[0] == NULL)
		return (-1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static struct s_gnl	strct[256];
	int					l;

	l = 0;
	if (!line)
		return (-1);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		line[0] = NULL;
		return (-1);
	}
	strct[fd].b[BUFFER_SIZE] = '\0';
	strct[fd].fd = fd;
	if (strct[fd].b[0] == '\0')
		l = read(strct[fd].fd, strct[fd].b, BUFFER_SIZE);
	if (l == -1)
	{
		line[0] = NULL;
		return (-1);
	}
	if (findnewline(&strct[fd]) > -1)
		return (newline(&strct[fd], line));
	return (nonewline(l, &strct[fd], line));
}
