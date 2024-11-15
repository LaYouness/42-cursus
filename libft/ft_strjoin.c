/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaarare <ylaarare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 09:46:26 by ylaarare          #+#    #+#             */
/*   Updated: 2024/11/14 19:42:55 by ylaarare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	fl;
	size_t	sl;

	if (!s1 || !s2)
		return (NULL);
	fl = ft_strlen((char *)s1);
	sl = ft_strlen((char *)s2);
	newstr = malloc(fl + sl + 1);
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s1, fl + 1);
	ft_strlcpy(newstr + fl, s2, sl + 1);
	return (newstr);
}
