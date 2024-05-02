#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

int	count_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*ptr;
	int		negative;
	int		tmp;

	len = count_len(n);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	negative = 0;
	if (!ptr)
		return (NULL);
	if (n < 0)
		negative = 1;
	ptr[len] = '\0';
	while (len--)
	{
		tmp = (n % 10);
		if (tmp < 0)
			tmp = -tmp;
		ptr[len] = tmp + '0';
		n /= 10;
	}
	if (negative)
		ptr[0] = '-';
	return (ptr);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("usage : %s [number of line]\n", argv[0]);
		return (0);
	}

	int fd1 = open("./line.txt", O_WRONLY | O_CREAT, 0644);
	int fd2 = open("./newline.txt", O_WRONLY | O_CREAT, 0644);
	
	if (fd1 == -1 || fd2 == -1)
	{
		printf("open error\n");
		return (0);
	}

	for (int i = 1; i <= atoi(argv[1]); i++)
	{
		char *t = ft_itoa(i);
		write(fd1, t, strlen(t));
		write(fd1, "\n", 1);
		write(fd2, "\n", 1);
		free(t);
	}
	close(fd1);
	close(fd2);
}
