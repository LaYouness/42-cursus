/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaarare <ylaarare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:08:35 by ylaarare          #+#    #+#             */
/*   Updated: 2024/11/14 20:04:31 by ylaarare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dl;
	size_t	sl;
	size_t	stf;
	char	*d;
	char	*s;

	sl = ft_strlen(src);
	if (!dst && dstsize == 0)
		return (sl);
	dl = ft_strlen(dst);
	d = dst + dl;
	s = (char *)src;
	stf = dstsize - dl - 1;
	if (dstsize <= dl)
		return (dstsize + sl);
	while (stf-- && *s)
		*d++ = *s++;
	*d = 0;
	return (dl + sl);
}
