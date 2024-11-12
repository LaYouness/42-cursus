/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younessla <younessla@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:03:59 by ylaarare          #+#    #+#             */
/*   Updated: 2024/11/12 15:53:46 by younessla        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp( const char *first, const char *second, size_t length)
{
	unsigned char	*f;
	unsigned char	*s;

	f = (unsigned char *)first;
	s = (unsigned char *)second;
	while (length-- && (*f || *s))
	{
		if (*f != *s)
			return (*f - *s);
		f++;
		s++;
	}
	return (0);
}
