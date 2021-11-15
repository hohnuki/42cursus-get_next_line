#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
int	main(int ac, char **av)
{
	char	*line;
	int		ret;
	int		i;
	int		*fds;
	int		index;
	int		k;
	int		f;
	i = 1;
	if (ac <= 1)
		return (0);
	else if (ac >= 2)
	{
		index = 1;
		fds = (int *)malloc(sizeof(int) * (ac));
		while (index < ac)
		{
			fds[index - 1] = open(av[index], O_RDONLY);
			index++;
		}
		index = 0;
		printf("_________________result_________________\n");
		while (1)
		{
			k = 0;
			f = 0;
			if(fds[index] != -1)
			{
				ret = get_next_line(fds[index], &line);
				if (ret <= 0)
				{	
					fds[index] = -1;
					while  (k < ac - 1)
					{
						if (fds[k] == -1)
							f += 1;
						k++;
					}
					if (f == ac - 1)
						break ;
				}
				printf("%d:%s\n", i++, line);
				free(line);
			}
			if (ret == -1)
				break;
			index++;
			if (index == ac - 1)
				index = 0;

		}
		free(line);
		printf("TRUE%d:%s\n", i, line);
		printf("_________________result_________________\n");
	}
	return (0);
 	
}
