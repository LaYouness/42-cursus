#include "get_next_line.h"

char	*get_line(s_list *list, size_t index)
{
	char	*line;
	s_list	*current;
	char	*last_part;
	size_t	i;

	line = malloc(1);
	*line = 0;
	current = list;
	while (current->next)
	{
		line = ft_strjoin(line, current->content);
		if (!line)
			return (NULL);
		current = current->next;
	}
	last_part = malloc(index);
	i = 0;
	while (i < index)
	{
		last_part[i] = current->content[i];
		i++;
	}
	return (ft_strjoin(line, last_part));
}
char *get_next_line(int fd)
{
	char				*buffer;
	static s_list		*head;
	int					read_n;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_n = read(fd, buffer, BUFFER_SIZE);
	if (read_n < 0 || !ft_lstadd_back(&head, ft_lstnew(buffer)))
			return (ft_lstclear(&head));
	if (read_n == 0 || ft_strchr(buffer, '\n'))
		return (get_line(head, ft_strchr(buffer, '\n') - buffer + 1));
	else
		return (get_next_line(fd));
}
