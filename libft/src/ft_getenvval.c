/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_getenvval.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/17 02:40:22 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 16:56:29 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_getenvval(char **envp, char *var)
{
	char	*value;
	int		i;
	char	*temp;

	temp = ft_strjoin(var, "=");
	i = -1;
	while (envp[++i])
		if (ft_strncmp(envp[i], temp, ft_strlen(temp)) == 0)
			break ;
	if (!envp[i])
	{
		free(temp);
		return (NULL);
	}
	value = ft_substr(envp[i], ft_strlen(temp), ft_strlen(envp[i]));
	free(temp);
	return (value);
}
