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

	if (targetNodeList == NULL || frontNodeList == NULL) // Q) �ǹ������� �̰� ���� ���� �ʳ�? �Լ������� NULL������ ����� �ϴ°� ��ü������ ȿ�����ϰ� ����.
	{
		return;
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

struct NODE_LIST *insertNodeBack(struct NODE_LIST *targetNodeList, struct NODE_LIST *backNodeList)
{
	struct NODE_LIST *rNode; // return-node
	struct NODE_LIST *bNode; // back-node
	struct NODE_LIST *tNode; // tail-node

							 // PARAMETER NULL CHECK

	if (targetNodeList == NULL || backNodeList == NULL) // Q) �ǹ������� �̰� ���� ���� �ʳ�? �Լ������� NULL������ ����� �ϴ°� ��ü������ ȿ�����ϰ� ����.
	{
		return;
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

int getNodeCount(struct NODE_LIST *nodeList)
{
	int nCnt; // node-count
	struct NODE_LIST *pNode; // pointer-node

	if (nodeList == NULL)
	{
		return 0; // Q) ��������� ���ϰ� 0 �ٷ���°� ��������(0��)���� ������?
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

void setNodeData(struct NODE_LIST *targetNode, const char *message)
{
	// �޸��Ҵ��ؼ� �Ķ���Ͱ� string copy

	if (targetNode->data.message != NULL)
	{
		free(targetNode->data.message);
	}

	targetNode->data.message = malloc(sizeof(char) * (strlen(message) + 2)); // Q) 2bytes���� ���� ����Ϸ��� �� ���� 1byte�� �ƴ϶� 2bytes������ �ξ�� �Ǵ� �ɱ�?
	strcpy(targetNode->data.message, message);
}

void delNodeData(struct NODE_LIST *targetNode)
{
	// �Ҵ������ϰ� NULL�� �ǵ�����.

	free(targetNode->data.message);
	targetNode->data.message = NULL;
}

struct NODE_LIST *cut(struct NODE_LIST *cutNode)
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

struct NODE_LIST *getHeadNode(struct NODE_LIST *nodeList)
{
	struct NODE_LIST *iter; // Q) ���ɶ����� nodeList�� �״�� iteratoró�� ���°� ������? �����̸� ��Ȱ������ �̷��� ���� ���� ���°� ������?
	iter = nodeList;

	while (iter->frontNode != NULL)
	{
		iter = iter->frontNode;
	}

	return iter;
}

struct NODE_LIST *getTailNode(struct NODE_LIST *nodeList)
{
	struct NODE_LIST *iter; // Q) ���ɶ����� nodeList�� �״�� iteratoró�� ���°� ������? �����̸� ��Ȱ������ �̷��� ���� ���� ���°� ������?
	iter = nodeList;

	while (iter->backNode != NULL)
	{
		iter = iter->backNode;
	}

	return iter;
}