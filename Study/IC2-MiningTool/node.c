#include "node.h"
#include <stdlib.h>
#include <assert.h>

struct NODE *createNode(int x, int y, int range)
{
	struct NODE *newNode = malloc(sizeof(struct NODE) * 1);

	newNode->x = x;
	newNode->y = y;
	newNode->range = range;
	newNode->backNode = NULL;
	newNode->frontNode = NULL;

	return newNode;
}

struct NODE *insertNodeFront(struct NODE *targetNodeList, struct NODE *frontNodeList)
{
	struct NODE *rNode; // return-node
	struct NODE *fNode; // front-node
	struct NODE *tNode; // tail-node

	// PARAMETER NULL CHECK

	if (targetNodeList == NULL || frontNodeList == NULL) // Q) 실무에서는 이거 빼도 되지 않나? 함수설명서에 NULL값쓰지 말라고 하는게 전체적으로 효율적일것 같다.
	{
		assert(0);
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

struct NODE *insertNodeBack(struct NODE *targetNodeList, struct NODE *backNodeList)
{
	struct NODE *rNode; // return-node
	struct NODE *bNode; // back-node
	struct NODE *tNode; // tail-node

	// PARAMETER NULL CHECK

	if (targetNodeList == NULL || backNodeList == NULL) // Q) 실무에서는 이거 빼도 되지 않나? 함수설명서에 NULL값쓰지 말라고 하는게 전체적으로 효율적일것 같다.
	{
		assert(0);
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

int getNodeCount(struct NODE *nodeList)
{
	int nCnt; // node-count
	struct NODE *pNode; // pointer-node

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

struct NODE *cutNode(struct NODE *cutNode)
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

struct NODE *getHeadNode(struct NODE *nodeList)
{
	struct NODE *iter; // Q) 성능때문에 nodeList를 그대로 iterator처럼 쓰는게 맞을까? 변수이름 역활때문에 이렇게 새로 만들어서 쓰는게 맞을까?
	iter = nodeList;

	while (iter->frontNode != NULL)
	{
		iter = iter->frontNode;
	}

	return iter;
}

struct NODE *getTailNode(struct NODE *nodeList)
{
	struct NODE *iter; // Q) 성능때문에 nodeList를 그대로 iterator처럼 쓰는게 맞을까? 변수이름 역활때문에 이렇게 새로 만들어서 쓰는게 맞을까?
	iter = nodeList;

	while (iter->backNode != NULL)
	{
		iter = iter->backNode;
	}

	return iter;
}

void delNode(struct NODE *targetNode)
{
	cutNode(targetNode);
	free(targetNode);
}

struct NODE *delNodeList(struct NODE *nodeList)
{
	struct NODE *rNode; // return-node
	struct NODE *tNode; // target-node
	struct NODE *iNode; // iterator-node

	if (nodeList == NULL)  // Q) 실무에서는 이거 빼도 되지 않나? 함수설명서에 NULL값쓰지 말라고 하는게 전체적으로 효율적일것 같다.
	{
		assert(0);
	}

	rNode = nodeList->frontNode;

	if (rNode != NULL)
	{
		rNode->backNode = NULL;
		nodeList->frontNode = NULL;
	}

	for (iNode = nodeList; iNode != NULL; delNode(tNode))
	{
		tNode = iNode;
		iNode = iNode->backNode;
	}

	return rNode;
}