/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younessla <younessla@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:12:09 by ylaarare          #+#    #+#             */
/*   Updated: 2024/11/13 09:24:37 by younessla        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*buffer;

	buffer = malloc(nmemb * size);
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, nmemb * size);
	return ((void *)buffer);
}
