/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test2.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <djonker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 21:06:17 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 17:08:44 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/libft.h"
#include <stdio.h>
#include <string.h>

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
	r = 0;
	if (strncmp(element[0]->next->content, "Hallo2", 6))
		r = 1;
	if (strncmp(element[1]->next->content, "Hallo3", 6))
		r = 1;
	ft_lstclear(list, &free);
	return (r);
}
