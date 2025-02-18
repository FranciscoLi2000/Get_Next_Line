#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *line;
    int line_number = 0;

    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line %d: %s", line_number + 1, line); // +1 para numeración humana
		free(line);
        line_number++;
	}
    printf("\nTotal lines: %d\n", line_number);
	close(fd);
	return (0);
}