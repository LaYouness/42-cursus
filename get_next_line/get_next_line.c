#include "get_next_line.h"

char	*get_line(s_list *list, size_t index)
{
	char	*line;
	s_list	*current;
	size_t	size_last_line;

	current = list;
	while (current->next)
	{
	line = ft_strjoin(line, list->content);
	if (!line)
		return (NULL);
	current = current->next;
	}
	while (index--)
	{
		l
	}
	
	return (line);
}
char *get_next_line(int fd)
{
	char				buffer[BUFFER_SIZE];
	char				*line;
	char				*content;
	static s_list		*head;
	s_list				*node;
	size_t				read_n;

	read_n = read(fd, buffer, BUFFER_SIZE);
	if (read_n < 0)
		return (NULL);
	content = ft_strdup(buffer);
	if (!content)
		return (NULL);
	node = ft_lstnew(content);
	if (!node)
		return (NULL);
	ft_lstadd_back(&head, node);
	if (ft_strchr(buffer, '\n'))
		return (get_line(head, ft_strchr(buffer, '\n') - buffer + 1));
}
