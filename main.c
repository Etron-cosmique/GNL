#include <stdio.h>
#include "get_next_line.h"

int	main()
{
	char	*s;
	int	fd = open("test.txt", O_RDONLY);
	s = get_next_line(fd);
	while ((s != NULL))
	{
		printf("%s", s);
		free(s);
		s = get_next_line(fd);
	}
	close(fd);
	return (0);
}
