#include "get_next_line.h"

char	*get_line(s_list *head)
{
	char	*line;

	if (head == NULL)
		return (NULL);
	line = malloc(line_len(head) + 1);
	if (!line)
		return (NULL);
	fill_line(line, head);
	return (line);
}

void	read_file(int fd, s_list **head)
{
	s_list	*node;
	char	*buffer;
	int		r;

	while (find_newline(*head) < 0)
	{
		node = malloc(sizeof(s_list));
		if (!node)
			return;
		buffer = malloc(BUFFER_SIZE);
		if (!buffer)
			return(free(node));
		r = read(fd, buffer, BUFFER_SIZE);
		if (r <= 0)
			return;
		buffer[r] = 0;
		node->content = buffer;
		node->next = NULL;
		if (*head == NULL)
			*head = node;
		else
			last_node(*head)->next = node;
	}
}
char	*get_reminder(s_list *head)
{
	s_list	*tail;
	int		index;
	char	*new_head_str;
	char	*tmp;
	size_t	size;

	if (!head)
		return (NULL);
	tail = last_node(head);
	index = find_newline(tail);
	if (index < 0)
		return (NULL);
	else
	{
		tmp = &(tail->content[index]);
		size = 0;
		while (*tmp++)
			size++;
		new_head_str = malloc(size + 1);
		tmp = new_head_str;
		while (tail->content[index])
			*tmp++ = tail->content[index++];
		new_head_str[size] = 0;
	}
	return (new_head_str);
}
char	*get_next_line(int fd)
{
	char			*line;
	char			*reminder;
	static s_list	*head;
	s_list			*new_head_node;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	read_file(fd, &head);
	line = get_line(head);
	reminder = get_reminder(head);
	clean_lst(&head);
	if (reminder && reminder[0])
	{
		new_head_node = malloc(sizeof(s_list));
		new_head_node->content = reminder;
		new_head_node->next = NULL;
		head = new_head_node;
	}
	else
		free(reminder);
	return (line);
}
