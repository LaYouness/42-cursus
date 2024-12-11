#include "get_next_line.h"

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