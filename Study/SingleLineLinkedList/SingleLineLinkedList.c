#include "node.h"
#include <stdio.h>

/*
1�ﰳ�� ������ �� ����üũ�ϰ� ���������� �����Ѵ�.
��, �������Ҷ� ������ ������ ���� �ʴ´�.
1�ﰳ�� ��ȭ�Ϸ��� 64bit�� �ſ� �˳��� ���뷮�� �ʿ��� �� ������, 32bit�� �޸� �Ҵ����� ���Ƽ� �ݹ� ���α׷� �浹���� ����ɰ� ����.
*/
void doTest(void);

int main(int argc, char *args[])
{
	doTest();
	
	return 0;
}

void doTest(void)
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
