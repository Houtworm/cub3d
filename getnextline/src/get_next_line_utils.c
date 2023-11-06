/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 18:52:21 by houtworm      #+#    #+#                 */
/*   Updated: 2023/10/26 18:52:21 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

size_t	gnl_strlen(char *str)
{
	size_t	a;

	a = 0;
	while (*str)
	{
		a++;
		str++;
	}
	return (a);
}

void	gnl_bzero(void *s, size_t n)
{
	char	*p;

	p = s;
	while (n)
	{
		*p = '\0';
		p++;
		n--;
	}
}

void	*gnl_memcpy(void *dst, const void *src, size_t n)
{
	char				*d;
	const char			*s;
	long unsigned int	i;

	i = 0;
	d = dst;
	s = src;
	while (n > i)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	int		c1;
	int		c2;
	int		l1;
	int		l2;
	char	*r;

	c1 = 0;
	c2 = 0;
	l1 = gnl_strlen((char *)s1);
	l2 = gnl_strlen((char *)s2);
	r = malloc(l1 + l2 + 1);
	if (r == NULL)
		return (r);
	while (c1 < l1)
	{
		r[c1] = s1[c1];
		c1++;
	}
	while (c2 < l2)
	{
		r[c1 + c2] = s2[c2];
		c2++;
	}
	r[c1 + c2] = '\0';
	return (r);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char				*r;
	long unsigned int	i;

	i = 0;
	r = malloc(len + 1);
	if (r == NULL)
		return (NULL);
	while (len > i)
	{
		r[i] = s[i + start];
		i++;
	}
	r[i] = '\0';
	return (r);
}
