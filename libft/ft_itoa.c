/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younessla <younessla@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 10:03:53 by ylaarare          #+#    #+#             */
/*   Updated: 2024/11/15 08:18:19 by younessla        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_nod(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static	char	*fillstr(int tsize, unsigned int un, char *s, int sign)
{
	char	*o;

	o = s;
	s = s + tsize - 1;
	*s-- = 0;
	while (--tsize)
	{
		*s-- = (un % 10) + 48;
		un /= 10;
	}
	if (sign)
		*o = '-';
	return (o);
}

char	*ft_itoa(int n)
{
	char			*s;
	int				size;
	int				sign;
	int				tsize;
	unsigned int	un;

	size = find_nod(n);
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		un = -n;
	}
	else
		un = n;
	tsize = size + 1 + sign;
	s = malloc(tsize);
	if (!s)
		return (NULL);
	s = fillstr(tsize, un, s, sign);
	return (s);
}
