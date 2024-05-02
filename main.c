#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	int fd = open("./tale.txt", O_RDONLY);
	int fdwr = open("./output.txt", O_WRONLY | O_CREAT, 0644);

	if (fd == -1)
	{
		printf("OPEN ERROR\n");
		return (0);
	}
	char *str;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
		{
			printf("FILE CLOSE\n");
			close(fd);
			return (0);
		}
		write(fdwr, str, strlen(str));
		printf("%s", str);
		free(str);
	}
}