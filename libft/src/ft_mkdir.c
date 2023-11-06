/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mkdir.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/17 20:10:59 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 17:00:01 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_mkdir(char *dirname, char **envp)
{
	char	**cmd;
	char	*command;
	char	**paths;
	int		pid;
	int		status;

	paths = ft_getpaths(envp, 0);
	if (!paths)
		return (1);
	command = ft_abspathcmd(paths, "mkdir");
	cmd = ft_calloc(3, 8);
	cmd[0] = ft_strdup("mkdir");
	cmd[1] = ft_strdup(dirname);
	cmd[2] = NULL;
	pid = fork();
	if (pid == 0)
	{
		execve(command, cmd, envp);
		exit(1);
	}
	waitpid(pid, &status, 0);
	free(command);
	ft_frearr(paths);
	ft_frearr(cmd);
	return (WEXITSTATUS(status));
}
