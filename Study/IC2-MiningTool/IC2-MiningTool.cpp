#include <stdio.h>
#include <conio.h>
#include "IC2-MiningTool.h"

MiningTool tool;

void help(void)
{
	printf("Ctrl+C: exit\n");
	printf("Ctrl+F: set filepath\n");
	printf("Ctrl+S: save to file\n");
	printf("Ctrl+O: open from file\n");
	printf("Arrows: move cursor\n");
	printf("h: help\n");
	printf("s: set cursor\n");
	printf("c: change mining range\n");
	printf("f: (force)set drill area\n");
	printf("x: set drill area\n");
	printf("u: unset drill area\n");
}

int main(int argc, char *args[])
{
	char pos[100];

	tool.getCursor(pos);
	puts(pos);

	help();

	while (true)
	{
		int c = getch();
		//printf("%d\n", c);

		switch (c)
		{
		case 6: // Ctrl+F
			char fpath[1024];
			printf("fpath>");
			scanf("%s", fpath);

			tool.setFilepath(fpath);
			break;
		case 19: // Ctrl+S
			printf("inturrpt code: %d\n", tool.fileSave());
			break;
		case 15: // Ctrl+O
			printf("inturrpt code: %d\n", tool.fileOpen());
			break;
		case 224: // Arrow Keys
			tool.move(getch());

			tool.getCursor(pos);
			puts(pos);
			break;
		case 's':
			int x, y;
			printf("x,y = ");
			scanf("%d %d", &x, &y);
			tool.set(x, y);

			tool.getCursor(pos);
			puts(pos);
			break;
		case 'c':
			int range;
			printf("(반경으로입력) range>");
			scanf("%d", &range);
			
			tool.setDrillRange(range);
			break;
		case 'x':
			if (tool.drillAreaClearCheck())
			{
				tool.addDrillArea();
				printf("OK\n");
			}
			else
			{
				printf("NO(Not clare area)\n");
			}
			break;
		case 'u':
			if (tool.delDrillArea())
			{
				printf("deleted drill area.\n");
			}
			else
			{
				printf("Not found drill here.\n");
			}
			break;
		case 'f':
			tool.addDrillArea();
			break;
		case 13:
			putchar('\n');
			break;
		case 'h':
			help();
			break;
		}

		if (c == 3) // Ctrl + C
		{
			break;
		}
	}
}


