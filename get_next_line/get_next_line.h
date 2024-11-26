#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINR_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
# endif

typedef struct		s_list
{
	char			*content;
	struct s_list	*next;
} 					s_list;

void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
s_list	*ft_lstnew(void *content);
int		ft_lstadd_back(s_list **lst, s_list *new);
void	*ft_lstclear(s_list **lst);
char	*get_next_line(int fd);
char	*get_line(s_list **list);

# endif