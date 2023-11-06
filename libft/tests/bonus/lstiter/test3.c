/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test3.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <djonker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 21:06:17 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 17:08:51 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/libft.h"
#include <stdio.h>
#include <string.h>

void	func(void *content)
{
	memset(content, 'a', 3);
}

int	main(void)
{
	int		r;
	t_list	**list;
	t_list	*element[3];
	char	*str[3];

	str[0] = strdup("Hallo1");
	str[1] = strdup("Hallo2");
	str[2] = strdup("Hallo3");
	element[0] = ft_lstnew(str[0]);
	element[1] = ft_lstnew(str[1]);
	element[2] = ft_lstnew(str[2]);
	list = &element[0];
	ft_lstadd_back(list, element[1]);
	ft_lstadd_back(list, element[2]);
	ft_lstdelone(element[1], &free);
	ft_lstiter(*list, &func);
	r = 0;
	if (strncmp(str[0], "aaalo1", 6) || strncmp(str[2], "Hallo3", 6))
		r = 1;
	free(element[0]);
	free(element[2]);
	free(str[0]);
	free(str[2]);
	return (r);
}
