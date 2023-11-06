/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_getpaths.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/20 16:39:22 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 16:59:06 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**ft_getpaths(char **envp, int i)
{
	char	**paths;
	char	**temp;
	char	*firsttemp;

	i = -1;
	while (envp[++i])
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
	if (!envp[i])
		return (0);
	else
		temp = ft_split(envp[i], ':');
	if (!temp)
		return (0);
	paths = ft_calloc(sizeof(char *) * (ft_arrlen(temp) + 1), 1);
	firsttemp = ft_substr(temp[0], 5, ft_strlen(temp[0]));
	if (!paths || !firsttemp)
		return (0);
	paths[0] = ft_strjoin(firsttemp, "/");
	free(firsttemp);
	i = 0;
	while (temp[++i])
		paths[i] = ft_strjoin(temp[i], "/");
	ft_frearr(temp);
	return (paths);
}
