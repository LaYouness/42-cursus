/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younessla <younessla@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:39:18 by ylaarare          #+#    #+#             */
/*   Updated: 2024/11/12 09:00:16 by younessla        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	char	*s;
	size_t	end;
	size_t	i;

	end = ft_strlen(str);
	s = str + end;
	i = end + 1;
	while (i--)
	{
		if (*s == (char)c)
			return (s);
		s--;
	}
	return (NULL);
}
