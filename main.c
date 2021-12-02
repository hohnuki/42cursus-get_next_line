#include "get_next_line.h"
#include <stdbool.h>
#include <libgen.h>
#include <string.h>

int	main(int argc, char **argv)
{
	(void)argv;
	char	*line = NULL;
	bool	flag = true;
	int		fd;
	size_t	i, j;

	i = 0;
	j = 0;
	if (argc == 2)
	{
		fd  = open(argv[1], O_RDONLY);
		while (flag)
		{
			line = get_next_line(fd);
			if (!line)
			{
				flag = false;
				printf("[loop(%zu)] EOF or ERROR\n", i);
			}
			else
			{
				j = 0;
				while (line[j])
				{
					printf("line[%zu] = %c\n", j, line[j]);
					j++;
				}
				printf("[loop(%zu)] %s-------------------------\n", i, line);
			}
			line = NULL;
			i++;
		}
		close(fd);
	}
	return (0);
}
