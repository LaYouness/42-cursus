/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younessla <younessla@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:40:34 by ylaarare          #+#    #+#             */
/*   Updated: 2024/11/12 09:31:48 by younessla        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
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
}
