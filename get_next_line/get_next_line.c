#include "get_next_line.h"

char	*get_line(char *buffer, char *pos)
{
	char	*line;
	char	*tmp;
	size_t	size_of_line;

	size_of_line = pos - buffer + 2;
	line = malloc(size_of_line);
	if (!line)
		return (NULL);
	tmp = line;
	while (--size_of_line)
		*tmp++ = *buffer++;
	*tmp = 0;
	return (line);
}
char *get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		tmp[BUFFER_SIZE];
	char		*new_line_pos;
	char		*line;

	while (1)
	{
		if (read(fd, buffer, BUFFER_SIZE) <= 0)
			return (NULL);
		new_line_pos = ft_strchr(buffer, '\n');
		if (new_line_pos)
		{
			line = get_line(buffer, new_line_pos);
			return (line);
		}
	}
}