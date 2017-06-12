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
			"0. ����\n"
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
		default:
			break;
		}
	} while (sw != '0');
	
	return 0;
}

void doTest2()
{
	struct NODE_LIST *nodeList;
	struct NODE_LIST *pNode;
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
	struct NODE_LIST *ls;
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
