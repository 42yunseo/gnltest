#include "../get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	int fd[3];
	fd[0] = open("./line.txt", O_RDONLY);
	fd[1] = open("./tinytale.txt", O_RDONLY);
	fd[2] = open("./newline.txt", O_RDONLY);

	int fdwr[3];
	fdwr[0] = open("./output1.txt", O_WRONLY | O_CREAT, 0644);
	fdwr[1] = open("./output2.txt", O_WRONLY | O_CREAT, 0644);
	fdwr[2] = open("./output3.txt", O_WRONLY | O_CREAT, 0644);

	if (fd[0] == -1 || fd[1] == -1 || fd[2] == -1 || fdwr[0] == -1 || fdwr[1] == -1 || fdwr[2] == -1)
	{
		printf("OPEN ERROR\n");
		return (0);
	}
	char *str[3];
	int i = 0;
	str[0] = get_next_line(fd[0]);
	printf("%s", str[0]);
	str[1] = get_next_line(fd[1]);
	printf("%s", str[1]);
	str[2] = get_next_line(fd[2]);
	printf("%s", str[2]);
	while (str[1] != NULL || str[1] != NULL || str[2] != NULL)
	{
		str[i] = get_next_line(fd[i]);
		if (str[i] == NULL)
		{
			i = (i + 1) % 3;
			continue;
		}
		write(fdwr[i], str[i], strlen(str[i]));
		write(1, str[i], strlen(str[i]));
		free(str[i]);
		i = (i + 1) % 3;
	}
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
}