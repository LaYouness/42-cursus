/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younessla <younessla@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:50:23 by ylaarare          #+#    #+#             */
/*   Updated: 2024/11/12 08:38:51 by younessla        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*finder;

	finder = (unsigned char *)s;
	while (n--)
	{
		if (*finder == c)
			return (finder);
		finder++;
	}
	return (NULL);
}
