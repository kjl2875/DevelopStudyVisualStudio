#include "node.h"
#include <stdio.h>
#include <time.h>

/*
1�ﰳ�� ������ �� ����üũ�ϰ� ���������� �����Ѵ�.
��, �������Ҷ� ������ ������ ���� �ʴ´�.
1�ﰳ�� ��ȭ�Ϸ��� 64bit�� �ſ� �˳��� ���뷮�� �ʿ��� �� ������, 32bit�� �޸� �Ҵ����� ���Ƽ� �ݹ� ���α׷� �浹���� ����ɰ� ����.
*/
void doTest(void);
/*
1�ﰳ�� ������ �� dataset, �׸��� ���������� �����Ѵ�.
*/
void doTest2(void);
/*
UserInterface ������
*/
void doTest3(void);

int main(int argc, char *args[])
{
	int sw;

	srand(time(NULL));

	do
	{
		printf(
			"What Test?\n"\
			"1. 1�ﰳ�� ������ �� ����üũ�ϰ� ���������� �����Ѵ�.\n"\
			"2. 1�ﰳ�� ������ �� dataset, �׸��� ���������� �����Ѵ�.\n"\
			"3. UserInterface ������.\n"\
			"0. ����\n"\
			"Number>"
		);
		sw = getch();
		printf("%c\n", sw);

		switch (sw)
		{
		case '1':
			doTest();
			break;
		case '2':
			doTest2();
			break;
		case '3':
			doTest3();
			break;
		default:
			break;
		}
	} while (sw != '0');
	
	return 0;
}

void doTest3() // TODO ���α׷� ���ǰ� Ŀ���� ������� �ݺ��� ���� ���ܼ� ���Ϸ� ���� �ɰ��ߵɵ�, �Դٰ� cut�� Ȱ���� ���� ���߸���Ʈ�� �ؾߵ�.
{
	int c;
	const char *helpMessage = "q: exit, h: help, a: add, arrow: move, d: del\n";
	struct NODE *list = NULL;
	struct NODE *tail = NULL;
	struct NODE *cursor = NULL;
	struct NODE *tNode;
	int cursorPosition = 0;
	int nodeCount = 0;

	printf(helpMessage);

	do
	{
		c = getch();

#define USE_SWITCH
#ifdef USE_SWITCH // Q) SWITCH���°� ������? if-else if-else if���°� ������?
		switch (c)
		{
		case 'h':
		{ // Q) �� ���� switch�� �ڵ������� 1-depth���� �����ִ°ɱ�?
			printf(helpMessage);
			break;
		}
		case 'a':
		{
			if (list != NULL)
			{
				insertNodeBack(tail, createNode(NULL));
				tail = tail->backNode;
			}
			else
			{
				list = createNode(NULL);
				tail = list;
				cursor = list;
			}

			printf("nodeCount: %d\n", ++nodeCount);
			break;
		}
		case 224: // 0xE0 // Q) ȭ��ǥ ������ �� �̰��� Ƣ����� ������?
		{
			switch (getch())
			{
			case 72: // up
				break;
			case 80: // down
				break;
			case 75: // left
			{
				if (cursor == NULL)
				{
					printf("nodeCount is 0\n");
					break;
				}

				if (cursor->frontNode != NULL)
				{
					cursor = cursor->frontNode;
					--cursorPosition;
				}
				
				printf("cursorPosition = %d\n", cursorPosition);
				break;
			}
			case 77: // right
			{
				if (cursor == NULL)
				{
					printf("nodeCount is 0\n");
					break;
				}

				if (cursor->backNode != NULL)
				{
					cursor = cursor->backNode;
					++cursorPosition;
				}
				
				printf("cursorPosition = %d\n", cursorPosition);
				break;
			}
			default:
			{
				break;
			}
			}

			break;
		}
		case 'd':
		{
			if (cursor == NULL)
			{
				printf("nodeCount is 0\n");
				break;
			}

			tNode = cursor;

			if (cursor->frontNode != NULL)
			{
				cursor = cursor->frontNode;
				--cursorPosition;

				if (tNode == tail)
				{
					tail = cursor;
				}
			}
			else if(cursor->backNode != NULL)
			{
				cursor = cursor->backNode;

				if (tNode == list)
				{
					list = cursor;
				}
			}
			else
			{
				cursor = NULL;
				list = NULL;
				tail = NULL;
			}

			delNode(tNode);
			--nodeCount;

			printf("cursorPosition = %d\n", cursorPosition);
			printf("nodeCount = %d\n", nodeCount); // Q) ���������δ� --nodeCount�� ����;� �±��ҰͰ�����, ��ɴ��� ������������ �̷��� �ߴٰ� ġ�� �̰Ը��� ���� ���Ƽ� �������� ���ٵǴٰ� ��ﰳ�� �ɼ��� �ִµ� ��������?
			
			break;
		}
		default:
		{
			break;
		}
		}
#else
		// ���� �ڵ尡 �����.
#endif

	} while (c != 'q');

	if (list != NULL)
	{
		delNodeList(list);
	}
}

void doTest2()
{
	struct NODE *nodeList;
	struct NODE *pNode;
	char *data;
	char buf[255];
	int i;
	
	// create list

	printf("Creating list\n");

	sprintf(buf, "%06d�ѱ���", rand());
	nodeList = createNode(buf);
	
	for (i = 0; i < 100000000; i++)
	{
		sprintf(buf, "%06d�ѱ���", rand());
		insertNodeBack(nodeList, createNode(buf));
	}

	// print list

	printf("Will print list\n");
	
	for (pNode = nodeList; pNode != NULL; pNode = pNode->backNode)
	{
		data = getNodeData(pNode);
		//printf("%s\n", data);
	}

	// delete list

	printf("Deleting list\n");

	delNodeList(nodeList);
}

void doTest()
{
	struct NODE *ls;
	int cnt;
	int nodeCount;

	// ����Ʈ ����

	printf("����Ʈ ������\n");

	ls = createNode(NULL);
	for (cnt = 1; cnt < 100000000; cnt++)
	{
		insertNodeBack(ls, createNode(NULL));
	}

	printf("����Ʈ �����Ϸ�\n");

	// ����Ʈ�� ��尳�� Ȯ��

	printf("����Ʈ�� ��尳�� Ȯ����\n");

	nodeCount = getNodeCount(ls);
	printf("nodeCount: %d\n", nodeCount);

	// ����Ʈ ����

	printf("����Ʈ ������\n");
	delNodeList(ls);

	printf("����Ʈ �����Ϸ�\n");
}
