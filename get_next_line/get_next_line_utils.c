#include "get_next_line.h"

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

	srcl = 0;
	while (s[srcl])
		srcl++;
	s = (char *)src;
	cpy = (char *)malloc(srcl + 1);
	if (!cpy)
		return (NULL);
	o = cpy;
	while (*s)
		*cpy++ = *s++;
	*cpy = '\0';
	return (o);
}

s_list	*ft_lstnew(void *content)
{
	s_list	*head;

	head = malloc(sizeof(s_list));
	if (!head)
		return (NULL);
	head->content = content;
	head->next = NULL;
	return (head);
}
void	ft_lstadd_back(s_list **lst, s_list *new)
{
	s_list	*current;

	if (!*lst)
		*lst = new;
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = new;
	new->next = NULL;
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	fl;
	size_t	sl;

	if (!s1 || !s2)
		return (NULL);
	fl = 0;
	while(s1[fl])
		fl++;
	sl = 0;
	while (s2[sl])
		sl++;
	newstr = malloc(fl + sl + 1);
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s1, fl + 1);
	ft_strlcpy(newstr + fl, s2, sl + 1);
	return (newstr);
}

