#include "node.h"
#include <stdio.h>

/*
1억개의 노드생성 및 개수체크하고 정상적으로 삭제한다.
단, 노드생성할때 데이터 생성은 하지 않는다.
1억개를 소화하려면 64bit에 매우 넉넉한 램용량이 필요할 것 같으며, 32bit는 메모리 할당폭이 좁아서 금방 프로그램 충돌나서 종료될것 같다.
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
