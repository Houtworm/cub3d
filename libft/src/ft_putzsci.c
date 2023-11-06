/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putzsci.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 21:45:39 by djonker       #+#    #+#                 */
/*   Updated: 2023/10/18 17:00:10 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_converttostring(long double n, int j)
{
	int			i;
	char		*r;
	char		*t1;
	char		*t2;

	i = ft_declen(n);
	t1 = ft_calloc(i + 1, 1);
	while (i > 0)
	{
		while (n < 1)
		{
			t1[j] = '0';
			j++;
			n = n * 10;
			i--;
		}
		n = n * 10;
		i--;
	}
	t2 = ft_ltoa(n);
	r = ft_strjoin(t1, t2);
	free(t1);
	free(t2);
	return (r);
}

int	ft_putscientificnotation(char *temp, int decimals, int zeroes)
{
	int		i;

	i = 1;
	while (temp[0 + zeroes] == '0')
		zeroes++;
	ft_putchar(temp[0 + zeroes]);
	if (decimals > 0)
	{
		ft_putchar('.');
		while (decimals >= i)
		{
			if (temp[i + zeroes] >= '0' && temp[i + zeroes] <= '9')
				ft_putchar(temp[i + zeroes]);
			else
				ft_putchar('0');
			i++;
		}
	}
	return (zeroes);
}

void	ft_putesignandnumber(long double num, int caps, int zeroes, int e)
{
	if (caps == 1)
		ft_putstr("E");
	else
		ft_putstr("e");
	if (zeroes > 0)
	{
		ft_putchar('-');
		ft_putznbr(zeroes, 2);
	}
	else if (e == 2)
	{
		ft_putchar('+');
		ft_putznbr(ft_intlen(num), 2);
	}
	else
	{
		ft_putchar('+');
		ft_putznbr(ft_intlen(num) - 1, 2);
	}
}

char	*ft_ninetoten(char *temp)
{
	char		*t1;
	char		*t2;

	t2 = ft_strdup(temp);
	free (temp);
	t2[0] = '0';
	t1 = ft_strdup("1\0");
	temp = ft_strjoin(t1, t2);
	free (t1);
	free (t2);
	return (temp);
}

void	ft_putzsci(long double number, int decimals, int caps)
{
	int			zeroes;
	int			round;
	char		*temp;
	int			extra;

	extra = 0;
	temp = ft_converttostring(number, 0);
	ft_around(temp, decimals);
	if (temp[0] == ':')
		extra++;
	free (temp);
	if (extra)
		decimals++;
	temp = ft_converttostring(number, 0);
	round = ft_around(temp, decimals);
	if (temp[0] == ':')
		extra++;
	if (extra == 2)
		temp = ft_ninetoten(temp);
	if (extra)
		decimals--;
	zeroes = ft_putscientificnotation(temp, decimals, 0);
	free (temp);
	ft_putesignandnumber(number, caps, zeroes, extra);
}
