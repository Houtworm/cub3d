/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 16:48:55 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/08 03:34:21 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_settexture(t_varlist *vl, char *line, int direction)
{
	int	i;

	i = 0;
	while (line[i] != '.')
		i++;
	if (direction == 1)
		vl->walltext[0] = mlx_load_png(&line[i]);
	if (direction == 2)
		vl->walltext[1] = mlx_load_png(&line[i]);
	if (direction == 3)
		vl->walltext[2] = mlx_load_png(&line[i]);
	if (direction == 4)
		vl->walltext[3] = mlx_load_png(&line[i]);
	return (0);
}

int	ft_setcolor(t_varlist *vl, char *line, int dest)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = 0;
	while (line[i] < '0' || line[i] > '9')
		i++;
	r = ft_atoi(&line[i]);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	while (line[i] < '0' || line[i] > '9')
		i++;
	g = ft_atoi(&line[i]);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	while (line[i] < '0' || line[i] > '9')
		i++;
	b = ft_atoi(&line[i]);
	if (dest == 1)
		vl->ccolor = (r << 24 | g << 16 | b << 8 | 255);
	if (dest == 2)
		vl->fcolor = (r << 24 | g << 16 | b << 8 | 255);
	return (0);
}

char	*ft_checkline(t_varlist *vl, char *line)
{
	if (line[0] == 'C' && line[1] == ' ')
	{
		if (!vl->ccolor)
			ft_setcolor(vl, line, 1);
		else
			return (" ceiling color");
	}
	else if (line[0] == 'F' && line[1] == ' ')
	{
		if (!vl->fcolor)
			ft_setcolor(vl, line, 2);
		else
			return (" floor color");
	}
	else if (!ft_strncmp(line, "NO ", 3))
	{
		if (!vl->walltext[0])
			ft_settexture(vl, line, 1);
		else
			return (" north texture");
	}
	return (NULL);
}

char	*ft_checkline2(t_varlist *vl, char *line)
{
	if (!ft_strncmp(line, "EA ", 3))
	{
		if (!vl->walltext[1])
			ft_settexture(vl, line, 2);
		else
			return (" east texture");
	}
	else if (!ft_strncmp(line, "SO ", 3))
	{
		if (!vl->walltext[2])
			ft_settexture(vl, line, 3);
		else
			return (" south texture");
	}
	else if (!ft_strncmp(line, "WE ", 3))
	{
		if (!vl->walltext[3])
			ft_settexture(vl, line, 4);
		else
			return (" west texture");
	}
	return (NULL);
}

t_varlist	ft_parseconfigfile(t_varlist vl, char *filename)
{
	int		fd;
	char	*line;
	char	*error;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_errorexit("file does not exist", "parseconfigfile", 1);
	while (get_next_line(fd, &line))
	{
		error = ft_checkline(&vl, line);
		if (!error)
			error = ft_checkline2(&vl, line);
		if (error)
			ft_errorexit("Double config declaration in .cub file", error, 1);
		if (vl.ccolor && vl.fcolor && vl.walltext[0] && vl.walltext[1] && vl.walltext[2] && vl.walltext[3])
		{
			vl.map = ft_getmap(&vl, fd);
			break ;
		}
		free(line);
	}
	close(fd);
	free(line);
	if (!vl.map)
		ft_errorexit("The map is too big, 1000x1000 max\n", "", 1);
	return (vl);
}
