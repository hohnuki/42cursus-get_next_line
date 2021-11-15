#include "get_next_line.h"

int main()
{
	char *line;
	while(1)
	{
		get_next_line(0,&line);
		printf("input:%s\n",line);
	}
	return (1);
}
