/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cpptostr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 12:17:01 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/19 00:19:29 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_cpptostr(char **cpp)
{
	int		i;
	char	*ret;
	char	*temp;
	char	*temp2;

	i = 1;
	if (cpp[0])
		temp2 = ft_strdup(cpp[0]);
	while (cpp[i])
	{
		temp = ft_strjoin(temp2, cpp[i]);
		free(temp2);
		temp2 = ft_strdup(temp);
		free(temp);
		i++;
	}
	ret = ft_strdup(temp2);
	free(temp2);
	return (ret);
}
