#include "node.h"
#include <stdio.h>
#include <time.h>

/*
1억개의 노드생성 및 개수체크하고 정상적으로 삭제한다.
단, 노드생성할때 데이터 생성은 하지 않는다.
1억개를 소화하려면 64bit에 매우 넉넉한 램용량이 필요할 것 같으며, 32bit는 메모리 할당폭이 좁아서 금방 프로그램 충돌나서 종료될것 같다.
*/
void doTest(void);
/*
1억개의 노드생성 및 dataset, 그리고 정상적으로 삭제한다.
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
			"1. 1억개의 노드생성 및 개수체크하고 정상적으로 삭제한다.\n"\
			"2. 1억개의 노드생성 및 dataset, 그리고 정상적으로 삭제한다.\n"\
			"0. 종료\n"
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

	sprintf(buf, "%06d한국어", rand());
	nodeList = createNode(buf);
	
	for (i = 0; i < 100000000; i++)
	{
		sprintf(buf, "%06d한국어", rand());
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

	// 리스트 생성

	printf("리스트 생성중\n");

	ls = createNode(NULL);
	for (cnt = 1; cnt < 100000000; cnt++)
	{
		insertNodeBack(ls, createNode(NULL));
	}

	printf("리스트 생성완료\n");

	// 리스트의 노드개수 확인

	printf("리스트의 노드개수 확인중\n");

	nodeCount = getNodeCount(ls);
	printf("nodeCount: %d\n", nodeCount);

	// 리스트 삭제

	printf("리스트 삭제중\n");
	delNodeList(ls);

	printf("리스트 삭제완료\n");
}
