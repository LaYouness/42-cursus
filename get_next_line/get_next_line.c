#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	size_t		size_of_line;
	char		*new_line_pos;

	if (read(fd, buffer, BUFFER_SIZE))
		return (NULL);
	new_line_pos = ft_strchr(buffer, '\n');
	if (new_line_pos)
	{
		size_of_line = new_line_pos - buffer + 1;
	}
	return (buffer);
}