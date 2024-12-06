#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
# endif

typedef struct		s_list
{
	char			*content;
	struct s_list	*next;
} 					s_list;

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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
char	*ft_strchr(const char *s, int c)
{
	char	*finder;
	char	ch;

	if (!s)
		return (NULL);
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
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char	*d;
	char	*s;
	size_t	sl;
	size_t	stf;

	d = dst;
	s = (char *)src;
	sl = ft_strlen(s);
	stf = size - 1;
	if (size == 0)
		return (sl);
	while (stf-- && *s)
		*d++ = *s++;
	*d = 0;
	return (sl);
}
void	lst_clear(s_list **head)
{
	s_list	*tmp;
	s_list	*current;

	if (!*head)
		return;	 
	current = *head;
	while (current)
	{
		tmp = current->next;
		free (current->content);
		free (current);
		current = tmp;
	}
}
void	lst_trim(s_list **head, s_list **tail)
{
	s_list	*new_head;
	char	*new_head_buf;
	char	*src;

	if (!head || !tail)
		return;
		// need free
	new_head = malloc(sizeof(s_list));
	new_head_buf = ft_calloc(1, BUFFER_SIZE + 1);
	if (!new_head || !new_head_buf)
	{
		lst_clear(head);
		return;
	}
	src = ft_strchr((*tail)->content, '\n');
	//printf("%p\n%s\n", src, (*head)->content);
	ft_strlcpy(new_head_buf, ++src, BUFFER_SIZE + 1);
	new_head->content = new_head_buf;
	new_head->next = NULL;
	lst_clear(head);
	*head = new_head;
	*tail = *head;
}

size_t	linelen(s_list	*head)
{
	size_t	line_len;
	int		i;

	line_len = 0;
	while (head)
	{
		i = 0;
		while ((head->content)[i] != '\n' && (head->content)[i++])
			line_len++;
		if ((head->content)[i] == '\n')
			return (line_len + 1);
		head = head->next;
	}
	return (line_len);
}
int	create_read(int fd, s_list	**head, s_list **tail)
{
	char	*buffer;
	s_list	*node;
	int		r;

	node = malloc(sizeof(s_list));
	buffer = ft_calloc(1, BUFFER_SIZE + 1);
	if (!buffer || !node)
		return (-1);
	r = read(fd, buffer, BUFFER_SIZE);
	if (r < 0)
	{
		free(node);
		free(buffer);
		return (r);
	}
	node->content = buffer;
	node->next = NULL;
	if (*head == NULL)
		*head = node;
	else
		(*tail)->next = node;
	*tail = node;
	return (r);
}

char	*get_line(s_list *head, s_list *tail)
{
	s_list	*current;
	char	*line;
	char	*line_c;
	int		i;

	if (!tail || !head)
		return (NULL);
	current = head;
	line = ft_calloc(1, linelen(head) + 1);
	line_c = line;
	while (current->next)
	{
		ft_strlcpy(line_c, (current->content), BUFFER_SIZE + 1);
		line_c += BUFFER_SIZE;
		current = current->next;
	}
	i = 0;
	while ((tail->content)[i])
	{
		*line_c++ = (tail->content)[i];
		if ((tail->content)[i] == '\n')
			break;
		i++;
	}
	return (line);
}
char	*get_next_line(int fd)
{
	static s_list	*head;
	static s_list	*tail;
	char			*line;
	int				r;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	while (tail == NULL || !ft_strchr(tail->content, '\n'))
	{
		r = create_read(fd, &head, &tail);
		if (r < 0)
			return (lst_clear(&head), NULL);
		line = get_line(head, tail);
		if (!line)
			return (lst_clear(&head), NULL);
		lst_trim(&head, &tail);
		return (line);
	}
	return (NULL);
}
int main()
{
	char    *line;
	int     fd;

	fd = open("file.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("line: %s", line);
		free(line);
	}

	close(fd);
}