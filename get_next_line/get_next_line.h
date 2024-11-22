#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINR_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif

typedef struct	string_list
{
	char		*content;
	s_list		*next;
} 				s_list;

char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
s_list	*ft_lstnew(void *content);
void	ft_lstadd_back(s_list **lst, s_list *new);

# endif