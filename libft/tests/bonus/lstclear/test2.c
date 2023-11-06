/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test2.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <djonker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 21:06:17 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 17:08:47 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../tmp/libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		r;
	t_list	**list;
	t_list	*element[2];
	char	*str[2];

	str[0] = strdup("Hallo1");
	str[1] = strdup("Hallo2");
	element[0] = ft_lstnew(str[0]);
	element[1] = ft_lstnew(str[1]);
	list = &element[1];
	ft_lstadd_front(list, element[0]);
	r = 0;
	ft_lstclear(list, NULL);
	if (*list != NULL)
		r = 1;
	free(str[0]);
	free(str[1]);
	return (r);
}
