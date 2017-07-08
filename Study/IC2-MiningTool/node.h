#pragma once

#ifdef	__cplusplus
extern "C" {
#endif

struct NODE {
	int range; // �ݰ氪
	int x;
	int y;

	struct NODE *frontNode;
	struct NODE *backNode;
};

/*
�ʱ�ȭ�� �� ��带 �ʱ�ȭ�� ������ ������ش�.(�޸��Ҵ�)
*/
struct NODE *createNode(int x, int y, int range);
/*
front�������� ��带 �����ش�.
����� ���� frontNodeList ���ʳ�尡 ���ϵȴ�.
*/
struct NODE *insertNodeFront(struct NODE *targetNodeList, struct NODE *frontNodeList);
/*
back�������� ��带 �����ش�.
����� ���� backNodeList ���ʳ�尡 ���ϵȴ�.
*/
struct NODE *insertNodeBack(struct NODE *targetNodeList, struct NODE *backNodeList);
/*
node�� ��ִ��� Ȯ�����ش�.
*/
int getNodeCount(struct NODE *nodeList);
/*
��带 �߶󳻱� �Ѵ�.
*/
struct NODE *cutNode(struct NODE *cutNode);
/*
nodelist�߿��� ���� ���� ��带 ã���ش�.
*/
struct NODE *getHeadNode(struct NODE *nodeList);
/*
nodelist�߿��� ���� ���� ��带 ã���ش�.
*/
struct NODE *getTailNode(struct NODE *nodeList);
/*
�ش� ��� 1���� �����Ѵ�.
*/
void delNode(struct NODE *targetNode);
/*
��帮��Ʈ�� �����Ѵ�.
nodeList�� back�κ��� ���� �����ϰ�, front�κ��� ���Ḹ �����ش�.
nodeList�� ùfront�κ��� �����Ѵ�.
*/
struct NODE *delNodeList(struct NODE *nodeList);

#ifdef	__cplusplus
		}
#endif