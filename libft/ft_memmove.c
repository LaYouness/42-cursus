/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaarare <ylaarare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:40:34 by ylaarare          #+#    #+#             */
/*   Updated: 2024/11/14 20:06:29 by ylaarare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*tmp;
	unsigned char	cont[1024];
	size_t			i;

	i = 0;
	s = (unsigned char *)src;
	tmp = (unsigned char *)dest;
	while (i < n)
		cont[i++] = *s++;
	i = 0;
	while (n--)
		*tmp++ = cont[i++];
	return (dest);
} */

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*tmp;

	if (src < dest)
	{
		s = (unsigned char *)src + n - 1;
		tmp = (unsigned char *)dest + n - 1;
		while (n--)
			*tmp-- = *s--;
		return (dest);
	}
	return (ft_memcpy(dest, src, n));
}
