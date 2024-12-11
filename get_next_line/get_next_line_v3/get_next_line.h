#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef	BUFFER_SIZE
#  define	BUFFER_SIZE 2
# endif

typedef struct 		s_list
{
	char			*content;
	struct s_list	*next;
}					s_list;

int		find_newline(s_list *head);
size_t	line_len(s_list *head);
void	fill_line(char *line, s_list *head);
void	clean_lst(s_list **head);
s_list	*last_node(s_list *head);
char	*get_line(s_list *head);
void	read_file(int fd, s_list **head);
char	*get_reminder(s_list *head);
char	*get_next_line(int fd);

#endif