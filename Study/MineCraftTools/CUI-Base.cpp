#include <stdio.h>
#include <string.h>

void ic2MiningTool(void);
unsigned int getOpCode(const char *cmd);
void strTrim(char *str);
void doHelp(void);

enum CMD {CMD_EXIT=0,CMD_HELP,CMD_IC2_MININGTOOL}; // cmdls客 index 嘎苗具凳
const char *cmdls[] = {"exit","help","ic2-miningTool"}; // CMD客 index 嘎苗具凳

int main(int argc, char *args[])
{
	int opCode;
	char cmd[255];

	while (true)
	{
		gets_s(cmd);
		strTrim(cmd);
		//printf("%s\n" ,cmd);

		opCode = getOpCode(cmd);
		//printf("%d\n", opCode);

		if (opCode == CMD_EXIT)
		{
			break;
		}

		if (opCode == -1)
		{
			continue;
		}

		switch (opCode)
		{
		case CMD_HELP:
			doHelp();
			break;
		case CMD_IC2_MININGTOOL:
			printf("OK.\n");
			ic2MiningTool();
			break;
		}
	}

	return 0;
}

void doHelp(void)
{
	int i;
	for (i = 0; i < sizeof(cmdls) / sizeof(int *); i++)
	{
		printf("%s ", cmdls[i]);
	}
	putchar('\n');
}

void strTrim(char *str)
{
	size_t *t, l;
	size_t i, si, ei;
	size_t s = strlen(str);

	if (s == 0)
	{
		return;
	}

	// set si(start index)

	t = &si;

	*t = 0;
	for (i = *t; i < s; i++)
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			*t = i;
			break;
		}
	}
	
	// set ei(end index)

	t = &ei;

	*t = s-1;
	for (i = *t; i >= si; i--)
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			*t = i;
			break;
		}
	}

	// rebuild

	if (si > 0)
	{
		for (l = 0, i = si; i <= ei; i++, l++)
		{
			str[l] = str[i];
		}
	}
	else
	{
		l = ei+1;
	}

	str[l] = '\0';
}

unsigned int getOpCode(const char *cmd)
{
	int i;
	for (i = 0; i < sizeof(cmdls) / sizeof(int *); i++)
	{
		if (strcmp(cmd, cmdls[i]) == 0)
		{
			return i;
		}
	}

	return -1;
}

void ic2MiningTool()
{
	char cmd[255];
	char *p;

	while (true)
	{
		gets_s(cmd);

		if (strcmp(cmd, "exit") == 0)
		{
			break;
		}

		if (strcmp(cmd, "help") == 0)
		{
			printf("exit, help\n");
			printf("add 123,123\n");
			continue;
		}
		
		p = strtok(cmd, " ");
		if (p != NULL)
		{
			if (strcmp(p, "add") == 0)
			{
				p = strtok(NULL, ",");
				printf("%s\n", p);

				if (p != NULL)
				{
					p = strtok(NULL, ",");
					printf("%s\n", p);
				}

				continue;
			}
		}
	}
}