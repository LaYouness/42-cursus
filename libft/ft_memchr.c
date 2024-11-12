/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younessla <younessla@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:50:23 by ylaarare          #+#    #+#             */
/*   Updated: 2024/11/12 15:14:40 by younessla        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*finder;
	unsigned char	character;

	character = (unsigned char)c;
	finder = (unsigned char *)s;
	while (n--)
	{
		if (*finder == character)
			return ((void *)finder);
		finder++;
	}
	return (NULL);
}
