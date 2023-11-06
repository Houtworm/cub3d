/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putflo_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 21:45:39 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 17:00:04 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putflo_fd(double n, int fd)
{
	int		i;
	int		f;

	i = n;
	f = ft_ftoi(n);
	ft_putnbr_fd(i, fd);
	ft_putchar_fd('.', fd);
	ft_putnbr_fd(f, fd);
}
