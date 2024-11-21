#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*finder;
	char	ch;

	ch = (char)c;
	finder = (char *)s;
	while (*finder)
	{
		if (*finder == ch)
			return (finder);
		finder++;
	}
	if (*finder == 0 && c == 0)
		return (finder);
	return (NULL);
}

char	*ft_strdup(const char *src)
{
	size_t	srcl;
	char	*cpy;
	char	*s;
	char	*o;

	s = (char *)src;
	srcl = ft_strlen(s);
	cpy = (char *)malloc(srcl + 1);
	if (!cpy)
		return (NULL);
	o = cpy;
	while (*s)
		*cpy++ = *s++;
	*cpy = '\0';
	return (o);
}

