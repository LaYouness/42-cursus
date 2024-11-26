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
int	ft_lstadd_back(s_list **lst, s_list *new)
{
	s_list	*current;
	if (!new)
		return (0);
	if (!*lst)
		*lst = new;
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = new;
	new->next = NULL;
	return (1);
}
void	*ft_lstclear(s_list **lst)
{
	s_list	*tmp;
	size_t	i;
	char	*reminder;

	if (!lst)
		return (NULL);
	while ((*lst)->next)
	{
		tmp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		(*lst) = tmp;
	}
	i = 0;
	while (((*lst)->content)[i] != '\n' && ((*lst)->content)[i])
		i++;
	if (((*lst)->content)[i] == '\n')
	{
	reminder = ft_calloc(1, ft_strlen((*lst)->content) - i + 1);
	ft_strlcpy(reminder, ((*lst)->content) + i + 1, ft_strlen((*lst)->content) - i + 1);
	*lst = ft_lstnew(reminder);
	}
	return (NULL);
}
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char	*d;
	char	*s;
	size_t	sl;
	size_t	stf;

	d = dst;
	s = (char *)src;
	sl = ft_strlen(src);
	stf = size - 1;
	if (size == 0)
		return (sl);
	while (stf-- && *s)
		*d++ = *s++;
	*d = 0;
	return (sl);
}
void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*buffer;
	size_t			n;
	int				i;
	buffer = malloc(nmemb * size);
	if (!buffer)
		return (NULL);
	n = nmemb * size;
	i = 0;
	while (n--)
		buffer[i++] = 0;
	return (buffer);
}
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
