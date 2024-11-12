/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younessla <younessla@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:25:12 by ylaarare          #+#    #+#             */
/*   Updated: 2024/11/12 08:59:46 by younessla        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*collector;
	char			*origine;
	size_t			len;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	collector = malloc(len + 1);
	if (!collector)
		return (NULL);
	origine = collector;
	while (*s)
		*collector++ = f(i++, *s++);
	*collector = 0;
	return (origine);
}
