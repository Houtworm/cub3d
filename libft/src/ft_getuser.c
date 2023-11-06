/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_getuser.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/17 02:40:22 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/18 16:59:09 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_getuser(char **envp)
{
	char	*user;
	int		i;

	i = -1;
	while (envp[++i])
		if (ft_strncmp(envp[i], "USER=", 5) == 0)
			break ;
	if (!envp[i])
		return (NULL);
	user = ft_substr(envp[i], 5, ft_strlen(envp[i]));
	return (user);
}
