/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   line.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 16:48:55 by houtworm      #+#    #+#                 */
/*   Updated: 2024/03/14 12:50:57 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_settexture(t_varlist *vl, char *line, int direction)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '.')
		i++;
	if (line[i] != '.' || access(&line[i], F_OK))
		ft_errorexit("Problem parsing wall texture ", line, 1);
	if (direction == 1)
		vl->walltxt[0] = mlx_load_png(&line[i]);
	if (direction == 2)
		vl->walltxt[1] = mlx_load_png(&line[i]);
	if (direction == 3)
		vl->walltxt[2] = mlx_load_png(&line[i]);
	if (direction == 4)
		vl->walltxt[3] = mlx_load_png(&line[i]);
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

char	*ft_checklinecfn(t_varlist *vl, char *line)
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
		if (!vl->walltxt[0])
			ft_settexture(vl, line, 1);
		else
			return (" north texture");
	}
	return (NULL);
}

char	*ft_checklineesw(t_varlist *vl, char *line)
{
	if (!ft_strncmp(line, "EA ", 3))
	{
		if (!vl->walltxt[1])
			ft_settexture(vl, line, 2);
		else
			return (" east texture");
	}
	else if (!ft_strncmp(line, "SO ", 3))
	{
		if (!vl->walltxt[2])
			ft_settexture(vl, line, 3);
		else
			return (" south texture");
	}
	else if (!ft_strncmp(line, "WE ", 3))
	{
		if (!vl->walltxt[3])
			ft_settexture(vl, line, 4);
		else
			return (" west texture");
	}
	return (NULL);
}

void	ft_checkline(t_varlist *vl, char *line)
{
	char	*error;

	error = ft_checklinecfn(vl, line);
	if (!error)
		error = ft_checklineesw(vl, line);
	if (error)
		ft_errorexit(error, "Double config declaration in .cub file", 1);
}
