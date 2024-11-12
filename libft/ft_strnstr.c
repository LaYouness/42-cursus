/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younessla <younessla@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:31:02 by ylaarare          #+#    #+#             */
/*   Updated: 2024/11/12 16:11:30 by younessla        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	char	*l;
	size_t	ll;
	size_t	passed;

	l = (char *)little;
	if (*l == 0)
		return ((char *)big);
	passed = 0;
	b = (char *)big;
	ll = ft_strlen(l);
	while (len && passed <= len && *b)
	{
		if ((len - passed++) >= ll && ft_strncmp(b, l, ll) == 0)
			return (b);
		b++;
		len--;
	}
	return (NULL);
}
