#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

typedef struct t_list
{
	char			*content;
	struct t_list	*next;
}					t_list;

int		find_newline(t_list *head);
size_t	line_len(t_list *head);
void	fill_line(char *line, t_list *head);
void	clean_lst(t_list **head);
t_list	*last_node(t_list *head);
char	*get_line(t_list *head);
void	read_file(int fd, t_list **head);
char	*get_reminder(t_list *head);
char	*get_next_line(int fd);

#endif