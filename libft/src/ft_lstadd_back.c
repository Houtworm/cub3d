/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 18:48:54 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 16:59:51 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*l;

	if (lst && new)
	{
		if (*lst)
		{
			l = ft_lstlast(*lst);
			l->next = new;
		}
		else
			*lst = new;
	}
}
