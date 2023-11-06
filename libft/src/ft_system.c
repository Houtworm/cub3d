/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_system.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/20 16:39:22 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/25 09:33:24 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_systemfork(char **cmd, char **paths, char **envp, char *file)
{
	int		pid;
	int		fd;
	char	*command;

	command = ft_abspathcmd(paths, cmd[0]);
	pid = fork();
	if (pid == 0)
	{
		fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0666);
		if (fd == -1)
			exit(1);
		dup2(fd, 1);
		execve(command, cmd, envp);
		ft_putstr_fd("command not found: ", 2);
		ft_putendl_fd(command, 2);
		close(fd);
		exit(1);
	}
	waitpid(pid, NULL, 0);
	ft_frearr(paths);
	ft_frearr(cmd);
	free(command);
}

char	*ft_system(char *command, char **envp, char *file)
{
	char	**cmd;
	char	**paths;
	int		pid;
	int		fd;

	cmd = ft_split(command, ' ');
	paths = ft_getpaths(envp, pid);
	if (!paths)
	{
		command = ft_strdup(cmd[0]);
		ft_frearr(cmd);
		return (command);
	}
	ft_systemfork(cmd, paths, envp, file);
	command = ft_calloc(8 * 2000, 1);
	fd = open(file, O_RDONLY);
	pid = read(fd, command, 1000);
	close(fd);
	if (pid == 1)
	{
		free(command);
		return (NULL);
	}
	command[pid - 1] = '\0';
	return (command);
}
