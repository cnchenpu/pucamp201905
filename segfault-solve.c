#include <stdio.h>
#include <stdlib.h>

int main(int arge, char *argv[])
{
	char *buf;

	//buf = malloc(1 << 31);
	buf = malloc(1024);

	fgets(buf, 1024, stdin);
	printf("%s\n", buf);

	return 1;
}

