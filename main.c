#include "get_next_line.h"

int	main(void)
{
	int	fd;
	int	i;
	char *line;

	fd = open("sample2.txt", O_RDONLY);
	i = 0;
	if (fd == -1)
		printf("file can't open\n");
	while (get_next_line(fd, &line) > 0);
	return (0);
}
