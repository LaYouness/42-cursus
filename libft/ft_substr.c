/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younessla <younessla@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 09:13:43 by ylaarare          #+#    #+#             */
/*   Updated: 2024/11/12 09:01:14 by younessla        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	sl;
	size_t	subsize;
	char	*substr;
	char	*filler;

	sl = ft_strlen((char *)s);
	if (start >= sl || len == 0)
		return (NULL);
	if (len <= sl - start)
		subsize = len + 1;
	else
		subsize = sl - start + 1;
	substr = malloc(subsize);
	if (!substr)
		return (NULL);
	filler = substr;
	while ((subsize--) - 1 > 0 && *s + start)
		*filler++ = *s + start++;
	*filler = 0;
	return (substr);
}
