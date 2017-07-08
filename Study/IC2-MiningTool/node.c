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

	if (targetNodeList == NULL || frontNodeList == NULL) // Q) �ǹ������� �̰� ���� ���� �ʳ�? �Լ��������� NULL������ ����� �ϴ°� ��ü������ ȿ�����ϰ� ����.
	{
		assert(0);
	}

	// �����Ͱ� ���������� ����

	rNode = frontNodeList->frontNode;
	fNode = targetNodeList->frontNode;
	tNode = getTailNode(frontNodeList);

	// targetNodeList���ʿ� frontNodeList�� ����. (�㸮�� �߸� targetNodeList�� �պκ��� fNode�� ����)

	targetNodeList->frontNode = tNode;
	tNode->backNode = targetNodeList;

	// frontNodeList ���ʿ� ������ fNode�� ����.

	if (fNode != NULL)
	{
		frontNodeList->frontNode = fNode;
		fNode->backNode = frontNodeList;
	}

	// frontNodeList�� ������ headNode�� �ƴ� �˻��� ��带 headó�� ������������ �ֱ⶧���� Ȱ���϶�� front���� ����.

	return rNode;
}

struct NODE *insertNodeBack(struct NODE *targetNodeList, struct NODE *backNodeList)
{
	struct NODE *rNode; // return-node
	struct NODE *bNode; // back-node
	struct NODE *tNode; // tail-node

	// PARAMETER NULL CHECK

	if (targetNodeList == NULL || backNodeList == NULL) // Q) �ǹ������� �̰� ���� ���� �ʳ�? �Լ��������� NULL������ ����� �ϴ°� ��ü������ ȿ�����ϰ� ����.
	{
		assert(0);
	}

	// �����Ͱ� ���������� ����

	rNode = backNodeList->frontNode;
	bNode = targetNodeList->backNode;
	tNode = getTailNode(backNodeList);

	// targetNodeList���ʿ� backNodeList�� ����. (�㸮�� �߸� targetNodeList�� �޺κ��� bNode�� ����)

	targetNodeList->backNode = backNodeList;
	backNodeList->frontNode = targetNodeList;

	// backNodeList�� tail��� ���ʿ� ������ bNode�� ����.

	if (bNode != NULL)
	{
		tNode->backNode = bNode;
		bNode->frontNode = tNode;
	}

	// backNodeList�� ������ headNode�� �ƴ� �˻��� ��带 headó�� ������������ �ֱ⶧���� Ȱ���϶�� front���� ����.

	return rNode;
}

int getNodeCount(struct NODE *nodeList)
{
	int nCnt; // node-count
	struct NODE *pNode; // pointer-node

	if (nodeList == NULL)
	{
		return 0; // Q) ����������� ���ϰ� 0 �ٷ���°� ��������(0��)���� ������?
	}

	// �������鼭 he

#define USE_FOR_CASE // Q) �̶��� for, while�߿��� ����� �� ������?

#ifdef USE_FOR_CASE

	for (nCnt = 1, pNode = nodeList; pNode->backNode != NULL; nCnt++)  // Q) �̽������� �ʱ�ȭ�� �ʿ��� ��, C���� ���߿� �ʱ�ȭ �ϴ°� ���ɻ����� ������?
	{
		pNode = pNode->backNode;
	}

#else

	pNode = nodeList; // Q) �̽������� �ʱ�ȭ�� �ʿ��� ��, C���� ���߿� �ʱ�ȭ �ϴ°� ���ɻ����� ������?
	nCnt = 1; // Q) nCnt=1�� ������? nCnt++�� ������?

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
	// ������带 �����Ͽ� �յڳ�� ������ ���������ش�.

	if (cutNode->frontNode != NULL)
	{
		cutNode->frontNode->backNode = cutNode->backNode;
	}

	if (cutNode->backNode != NULL)
	{
		cutNode->backNode->frontNode = cutNode->frontNode;
	}

	// ��������� ��ũ�� �����ְ� �Ҵ����� ���ϰ� �״�� �Ѱ��ش�.

	cutNode->frontNode = NULL;
	cutNode->backNode = NULL;

	return cutNode;
}

struct NODE *getHeadNode(struct NODE *nodeList)
{
	struct NODE *iter; // Q) ���ɶ����� nodeList�� �״�� iteratoró�� ���°� ������? �����̸� ��Ȱ������ �̷��� ���� ���� ���°� ������?
	iter = nodeList;

	while (iter->frontNode != NULL)
	{
		iter = iter->frontNode;
	}

	return iter;
}

struct NODE *getTailNode(struct NODE *nodeList)
{
	struct NODE *iter; // Q) ���ɶ����� nodeList�� �״�� iteratoró�� ���°� ������? �����̸� ��Ȱ������ �̷��� ���� ���� ���°� ������?
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

	if (nodeList == NULL)  // Q) �ǹ������� �̰� ���� ���� �ʳ�? �Լ��������� NULL������ ����� �ϴ°� ��ü������ ȿ�����ϰ� ����.
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