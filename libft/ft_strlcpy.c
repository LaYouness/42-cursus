/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younessla <younessla@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:31:51 by ylaarare          #+#    #+#             */
/*   Updated: 2024/11/12 08:59:12 by younessla        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char	*d;
	char	*s;
	size_t	dl;
	size_t	sl;
	size_t	stf;

	d = dst;
	s = (char *)src;
	dl = ft_strlen(dst);
	sl = ft_strlen(src);
	stf = size - 1;
	if (size == 0)
		return (sl);
	while (stf-- && *s)
		*d++ = *s++;
	*d = 0;
	return (sl);
}
