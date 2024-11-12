/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younessla <younessla@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 09:46:26 by ylaarare          #+#    #+#             */
/*   Updated: 2024/11/12 08:58:24 by younessla        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	fl;
	size_t	sl;

	if (!s1 && !s2)
		return (NULL);
	fl = ft_strlen((char *)s1);
	sl = ft_strlen((char *)s2);
	newstr = malloc(fl + sl + 1);
	if (!newstr)
		return (NULL);
	ft_strlcat(newstr, s1, fl + sl + 1);
	ft_strlcat(newstr, s2, fl + sl + 1);
	return (newstr);
}
