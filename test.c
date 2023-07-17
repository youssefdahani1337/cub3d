# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

int main()
{
	int fd = open("libft", O_RDONLY);
	if (fd == -1)
		perror("error");
	
}