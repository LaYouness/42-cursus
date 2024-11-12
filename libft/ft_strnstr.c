/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younessla <younessla@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:31:02 by ylaarare          #+#    #+#             */
/*   Updated: 2024/11/12 21:26:02 by younessla        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	char	*l;
	size_t	ll;
	size_t	i;

	l = (char *)little;
	b = (char *)big;
	ll = ft_strlen(l);
	if (ll == 0)
		return ((char *)big);
	i = 0;
	while (i < len && *b)
	{
		if ((ft_strncmp(b, l, ll) == 0) && i + ll <= len)
			return (b);
		b++;
		i++;
	}
	return (NULL);
}
