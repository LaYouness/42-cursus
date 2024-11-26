#include "get_next_line.h"

int main()
{
	int fd;
	char *line;
	fd = open("file.txt", O_RDONLY);
	printf("line 1: %s", line = get_next_line(fd));
	free(line);
	printf("line 2: %s", line = get_next_line(fd));
	free(line);
	printf("line 3: %s", line = get_next_line(fd));
	free(line);
	close(fd);
}
