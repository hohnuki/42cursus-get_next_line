#include "get_next_line.h"
#include <stdbool.h>
#include <libgen.h>
#include <string.h>

int	main(int argc, char **argv)
{
	(void)argv;
	char	*line = NULL;
	bool	flag;
	int		fd;
	size_t	i;

	flag = true;
	i = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDWR);
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
				printf("[loop(%zu)] %s\n", i, line);
			}
			line = NULL;
			i++;
		}
		close(fd);
	}
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	(void)argv;
// 	int		fd;

// 	if (argc == 2)
// 	{
// 		fd  = open(argv[1], O_RDWR);
// 		printf("gnl_return = [%s]\n", get_next_line(fd));
// 		close(fd);
// 	}
// 	return (0);
// }
