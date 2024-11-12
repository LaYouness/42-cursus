/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younessla <younessla@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:12:09 by ylaarare          #+#    #+#             */
/*   Updated: 2024/11/12 09:33:51 by younessla        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			tts;
	unsigned char	*buffer;

	tts = nmemb * size;
	if (size == 0 || nmemb == 0)
		return (NULL);
	buffer = malloc(tts);
	ft_bzero(buffer, tts);
	return (buffer);
}
