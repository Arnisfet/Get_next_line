
#include "./cmake-build-debug/get_next_line.h"


int main()
{
	char *line;
	int fd;

	fd = 0;
	fd = open("/Users/mrudge/Desktop/Test/gnlTester/files/42_with_nl",
			  O_RDONLY);
	if (fd == -1)
		puts("error");
	while(get_next_line(fd, &line))
		printf("%s\n", line);

}