#pragma once

#include <string.h>

struct NODE_DATA {
	// TODO ���� data�� ���� ��ȹ�� ��� ��ȹ�� �ʿ���.
	char *message;
};

struct NODE_LIST {
	struct NODE_DATA data;

	struct NODE_LIST *frontNode;
	struct NODE_LIST *backNode;
};

/*
�ʱ�ȭ�� �� ��带 �ʱ�ȭ�� ������ ������ش�.(�޸��Ҵ�)
*/
struct NODE_LIST *createNode();
/*
front�������� ��带 �����ش�.
����� ���� frontNodeList ���ʳ�尡 ���ϵȴ�.
*/
struct NODE_LIST *insertNodeFront(struct NODE_LIST *targetNodeList, struct NODE_LIST *frontNodeList);
/*
back�������� ��带 �����ش�.
����� ���� backNodeList ���ʳ�尡 ���ϵȴ�.
*/
struct NODE_LIST *insertNodeBack(struct NODE_LIST *targetNodeList, struct NODE_LIST *backNodeList);
/*
node�� ��ִ��� Ȯ�����ش�.
*/
int getNodeCount(struct NODE_LIST *nodeList);
/*
��嵥���͸� �����Ѵ�.
*/
void setNodeData(struct NODE_LIST *targetNode, const char *message);
/*
��嵥���͸� �����Ѵ�.
*/
void delNodeData(struct NODE_LIST *targetNode);
/*
��带 �߶󳻱� �Ѵ�.
*/
struct NODE_LIST *cut(struct NODE_LIST *cutNode);
/*
nodelist�߿��� ���� ���� ��带 ã���ش�.
*/
struct NODE_LIST *getHeadNode(struct NODE_LIST *nodeList);
/*
nodelist�߿��� ���� ���� ��带 ã���ش�.
*/
struct NODE_LIST *getTailNode(struct NODE_LIST *nodeList);
