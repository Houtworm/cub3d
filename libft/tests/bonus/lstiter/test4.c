/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test4.c                                            :+:    :+:            */
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

int	main(void)
{
	int		r;
	t_list	**list;
	t_list	*element[1];
	char	*str[1];

	str[0] = strdup("Hallo1");
	element[0] = ft_lstnew(str[0]);
	list = &element[0];
	ft_lstiter(*list, NULL);
	r = 0;
	if (strncmp(str[0], "Hallo1", 6))
		r = 1;
	free(str[0]);
	free(*list);
	return (r);
}
