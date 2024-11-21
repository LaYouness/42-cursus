#include "get_next_line.h"

int main()
{
	int fd;

	fd = open("file.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	close(fd);
}