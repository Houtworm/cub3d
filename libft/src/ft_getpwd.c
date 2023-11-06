/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_getpwd.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/17 02:40:22 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 16:59:07 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_getpwd(char **envp, int slash)
{
	char	*pwd;
	char	*temp;
	int		i;

	i = -1;
	while (envp[++i])
		if (ft_strncmp(envp[i], "PWD=", 4) == 0)
			break ;
	if (!envp[i])
		return (NULL);
	temp = ft_substr(envp[i], 4, ft_strlen(envp[i]));
	if (!temp)
		return (NULL);
	if (slash)
		pwd = ft_strjoin(temp, "/");
	else
		pwd = ft_strjoin(temp, NULL);
	free(temp);
	return (pwd);
}
