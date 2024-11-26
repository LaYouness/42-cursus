#include "get_next_line.h"

char	*get_line(s_list **list)
{
	char	*line;
	s_list	*current;
	char	*last_part;
	size_t	i;

	line = ft_calloc(1, 1);
	current = *list;
	while (current->next)
	{
		line = ft_strjoin(line, current->content);
		if (!line)
			return (ft_lstclear(list));
		current = current->next;
	}
	i = 0;
	while ((current->content)[i] != '\n' && (current->content)[i])
		i++;
	last_part = ft_calloc(1, i + 2);
	ft_strlcpy(last_part, current->content, i + 2);
	return (ft_lstclear(list), ft_strjoin(line, last_part));
}
char *get_next_line(int fd)
{
	char				*buffer;
	static s_list		*head;
	int					read_n;

	buffer = ft_calloc(1, BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_n = read(fd, buffer, BUFFER_SIZE);
	if (read_n < 0 || !ft_lstadd_back(&head, ft_lstnew(buffer)))
			return (ft_lstclear(&head));
	if (read_n == 0 || ft_strchr(buffer, '\n'))
		return (get_line(&head));
	else
		return (get_next_line(fd));
}
