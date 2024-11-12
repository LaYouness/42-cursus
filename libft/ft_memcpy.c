/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younessla <younessla@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:20:45 by ylaarare          #+#    #+#             */
/*   Updated: 2024/11/12 13:44:52 by younessla        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*s;

	s = (unsigned char *)src;
	tmp = (unsigned char *)dest;
	while (n--)
		*tmp++ = *s++;
	return (dest);
}
