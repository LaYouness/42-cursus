#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#ifndef	BUFFER_SIZE
#define BUFFER_SIZE 2
#endif
typedef struct 		s_list
{
	char			*content;
	struct s_list	*next;
}					s_list;

int	find_newline(s_list *head)
{
	char	*finder;
	int		i;
	if (head == NULL)
		return (-1);
	i = 0;
	while (head)
	{
		finder = head->content;
		while (*finder)
		{
			if (*finder == '\n')
			{
				i++;
				return (i);
			}
			i++;
			finder++;
		}
		head = head->next;
	}
	return (-1);
}
size_t	line_len(s_list *head)
{
	char	*current;
	size_t	len;
	if (head == NULL)
		return 0;
	len = 0;
	while (head)
	{
		current = head->content;
		while (*current++)
		{
			if (*current == '\n')
			{
				len++;
				return (len);
			}
			len++;
		}
		head = head->next;
	}
	return (len);
}
void	clean_lst(s_list **head)
{
	s_list	*current;
	s_list	*tmp;
	if (*head == NULL)
		return;
	current = *head;
	while (current)
	{
		tmp = current;
		free(current->content);
		current = current->next;
		free(tmp);
	}
	*head = NULL;
	return;
}
s_list	*last_node(s_list *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}
void	fill_line(char *line, s_list *head)
{
	char	*current;

	if (!line || !head)
		return;
	while (head)
	{
		current = head->content;
		while (*current)
		{
			if ((*current == '\n'))
				{
					*line++ = *current;
					*line = 0;
					return;
				}
			*line++ = *current++; 
		}
		head = head->next;
	}
	*line = 0;
	return;
}
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
int main()
{
	int fd = open("file.txt",O_RDONLY);
	char *line;
	
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return 0;
}
