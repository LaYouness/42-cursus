/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younessla <younessla@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:03:59 by ylaarare          #+#    #+#             */
/*   Updated: 2024/11/12 08:59:52 by younessla        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp( const char *first, const char *second, size_t length)
{
	char	*f;
	char	*s;

	f = (char *)first;
	s = (char *)second;
	while (length-- && (*f || *s))
	{
		if (*f != *s)
			return (*f - *s);
		f++;
		s++;
	}
	return (0);
}
