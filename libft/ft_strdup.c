/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younessla <younessla@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 14:51:40 by ylaarare          #+#    #+#             */
/*   Updated: 2024/11/12 08:39:28 by younessla        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	srcl;
	char	*cpy;
	char	*s;
	char	*o;

	s = (char *)src;
	srcl = ft_strlen(s);
	cpy = (char *)malloc(srcl + 1);
	if (!cpy)
		return (NULL);
	o = cpy;
	while (*s)
		*cpy++ = *s++;
	*cpy = '\0';
	return (o);
}
