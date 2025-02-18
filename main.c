#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int fd;
	char *line;
    int line_number;

    if (argc != 2)
    {
        printf("Usage: %s <file name>\n", argv[0]);
        return (1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        printf("Error abriendo el archivo: %s\n", argv[1]);
        return (1);
    }
    line_number = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("[Line %d] %s", line_number, line);
		free(line);
        line_number++;
	}
	close(fd);
	return (0);
}