/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_gettimemsdate.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/17 20:10:03 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/19 00:04:18 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

long long	ft_gettimemsdate(char **envp, char *file)
{
	char		*date;
	long long	currenttime;

	date = ft_system("date +%s%3N", envp, file);
	currenttime = ft_atol(date);
	free(date);
	return (currenttime);
}
