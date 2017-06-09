#include "node.h"
#include <stdlib.h>

struct NODE_LIST *createNode()
{
	struct NODE_LIST *newNode = malloc(sizeof(struct NODE_LIST) * 1);

	newNode->data.message = NULL;
	newNode->backNode = NULL;
	newNode->frontNode = NULL;

	return newNode;
}

struct NODE_LIST *insertNodeFront(struct NODE_LIST *targetNodeList, struct NODE_LIST *frontNodeList)
{
	struct NODE_LIST *rNode; // return-node
	struct NODE_LIST *fNode; // front-node
	struct NODE_LIST *tNode; // tail-node

							 // PARAMETER NULL CHECK

	if (targetNodeList == NULL || frontNodeList == NULL) // Q) 실무에서는 이거 빼도 되지 않나? 함수설명서에 NULL값쓰지 말라고 하는게 전체적으로 효율적일것 같다.
	{
		return;
	}

	// 포인터값 보관용으로 저장

	rNode = frontNodeList->frontNode;
	fNode = targetNodeList->frontNode;
	tNode = getTailNode(frontNodeList);

	// targetNodeList앞쪽에 frontNodeList를 붙임. (허리가 잘린 targetNodeList의 앞부분은 fNode가 보관)

	targetNodeList->frontNode = tNode;
	tNode->backNode = targetNodeList;

	// frontNodeList 앞쪽에 저장한 fNode와 연결.

	if (fNode != NULL)
	{
		frontNodeList->frontNode = fNode;
		fNode->backNode = frontNodeList;
	}

	// frontNodeList값 넣을때 headNode가 아닌 검색중 노드를 head처럼 던져넣을수도 있기때문에 활용하라고 front값을 리턴.

	return rNode;
}

struct NODE_LIST *insertNodeBack(struct NODE_LIST *targetNodeList, struct NODE_LIST *backNodeList)
{
	struct NODE_LIST *rNode; // return-node
	struct NODE_LIST *bNode; // back-node
	struct NODE_LIST *tNode; // tail-node

							 // PARAMETER NULL CHECK

	if (targetNodeList == NULL || backNodeList == NULL) // Q) 실무에서는 이거 빼도 되지 않나? 함수설명서에 NULL값쓰지 말라고 하는게 전체적으로 효율적일것 같다.
	{
		return;
	}

	// 포인터값 보관용으로 저장

	rNode = backNodeList->frontNode;
	bNode = targetNodeList->backNode;
	tNode = getTailNode(backNodeList);

	// targetNodeList뒤쪽에 backNodeList를 붙임. (허리가 잘린 targetNodeList의 뒷부분은 bNode가 보관)

	targetNodeList->backNode = backNodeList;
	backNodeList->frontNode = targetNodeList;

	// backNodeList의 tail노드 뒤쪽에 저장한 bNode와 연결.

	if (bNode != NULL)
	{
		tNode->backNode = bNode;
		bNode->frontNode = tNode;
	}

	// backNodeList값 넣을때 headNode가 아닌 검색중 노드를 head처럼 던져넣을수도 있기때문에 활용하라고 front값을 리턴.

	return rNode;
}

int getNodeCount(struct NODE_LIST *nodeList)
{
	int nCnt; // node-count
	struct NODE_LIST *pNode; // pointer-node

	if (nodeList == NULL)
	{
		return 0; // Q) 어셈블리에서 리턴값 0 바로찍는게 변수리턴(0값)보다 빠를까?
	}

	// 개수세면서 he

#define USE_FOR_CASE // Q) 이때는 for, while중에서 어느게 더 빠를까?

#ifdef USE_FOR_CASE

	for (nCnt = 1, pNode = nodeList; pNode->backNode != NULL; nCnt++)  // Q) 이시점에서 초기화가 필요할 때, C언어에서 나중에 초기화 하는게 성능상으로 빠를까?
	{
		pNode = pNode->backNode;
	}

#else

	pNode = nodeList; // Q) 이시점에서 초기화가 필요할 때, C언어에서 나중에 초기화 하는게 성능상으로 빠를까?
	nCnt = 1; // Q) nCnt=1이 빠를까? nCnt++이 빠를까?

	while (pNode->backNode != NULL)
	{
		pNode = pNode->backNode;
		nCnt++;
	}

#endif

	return nCnt;
}

void setNodeData(struct NODE_LIST *targetNode, const char *message)
{
	// 메모리할당해서 파라미터값 string copy

	if (targetNode->data.message != NULL)
	{
		free(targetNode->data.message);
	}

	targetNode->data.message = malloc(sizeof(char) * (strlen(message) + 2)); // Q) 2bytes문자 재대로 출력하려면 왜 끝에 1byte가 아니라 2bytes공간을 두어야 되는 걸까?
	strcpy(targetNode->data.message, message);
}

void delNodeData(struct NODE_LIST *targetNode)
{
	// 할당해제하고 NULL로 되돌린다.

	free(targetNode->data.message);
	targetNode->data.message = NULL;
}

struct NODE_LIST *cut(struct NODE_LIST *cutNode)
{
	// 빠질노드를 감안하여 앞뒤노드 연결을 유지시켜준다.

	if (cutNode->frontNode != NULL)
	{
		cutNode->frontNode->backNode = cutNode->backNode;
	}

	if (cutNode->backNode != NULL)
	{
		cutNode->backNode->frontNode = cutNode->frontNode;
	}

	// 빠진노드의 링크만 끊어주고 할당해제 안하고 그대로 넘겨준다.

	cutNode->frontNode = NULL;
	cutNode->backNode = NULL;

	return cutNode;
}

struct NODE_LIST *getHeadNode(struct NODE_LIST *nodeList)
{
	struct NODE_LIST *iter; // Q) 성능때문에 nodeList를 그대로 iterator처럼 쓰는게 맞을까? 변수이름 역활때문에 이렇게 새로 만들어서 쓰는게 맞을까?
	iter = nodeList;

	while (iter->frontNode != NULL)
	{
		iter = iter->frontNode;
	}

	return iter;
}

struct NODE_LIST *getTailNode(struct NODE_LIST *nodeList)
{
	struct NODE_LIST *iter; // Q) 성능때문에 nodeList를 그대로 iterator처럼 쓰는게 맞을까? 변수이름 역활때문에 이렇게 새로 만들어서 쓰는게 맞을까?
	iter = nodeList;

	while (iter->backNode != NULL)
	{
		iter = iter->backNode;
	}

	return iter;
}