/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younessla <younessla@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:08:25 by ylaarare          #+#    #+#             */
/*   Updated: 2024/11/12 10:22:39 by younessla        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	cw(char *s, char c)
{
	size_t	now;

	now = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			now++;
			while (*s && *s != c)
				s++;
		}
	}
	return (now);
}

static size_t	low(char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s && *s++ != c)
		i++;
	return (i);
}

static void	free_all(char **start, char **end)
{
	while (start <= --end)
		free(*end);
	free(start);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	char	**word_to_word;
	size_t	now;
	size_t	wl;

	now = cw((char *)s, c);
	arr = malloc((now + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	word_to_word = arr;
	while (now-- + 1)
	{
		while (*s == c)
			s++;
		wl = low((char *)s, c);
		*word_to_word = malloc((wl + 1) * sizeof(char));
		if (!*word_to_word)
			return (free_all(arr, word_to_word), NULL);
		ft_strlcpy(*word_to_word, s, wl + 1);
		s = s + wl;
		word_to_word++;
	}
	return (*word_to_word = NULL, arr);
}
