#include <stdio.h>
#include <conio.h>

int main(int argc, char *argv[])
{
	int c;

	while (1)
	{
		c = getch();
		printf("%d\n", c);
	}

	return 0;
}