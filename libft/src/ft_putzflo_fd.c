/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putzflo_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 21:45:39 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 17:00:09 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putzflo_fd(double n, int e, int fd)
{
	int		i;
	int		f;
	int		l;

	i = n;
	f = ft_ftoi(n);
	l = ft_intlen(f) - e;
	ft_putnbr_fd(i, fd);
	ft_putchar_fd('.', fd);
	ft_putnbr_fd(f, fd);
	while (l != 0)
	{
		ft_putchar_fd('0', 1);
		l++;
	}
}
