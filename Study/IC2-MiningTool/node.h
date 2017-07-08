#pragma once

#ifdef	__cplusplus
extern "C" {
#endif

struct NODE {
	int range; // 반경값
	int x;
	int y;

	struct NODE *frontNode;
	struct NODE *backNode;
};

/*
초기화된 새 노드를 초기화된 값으로 만들어준다.(메모리할당)
*/
struct NODE *createNode(int x, int y, int range);
/*
front방향으로 노드를 끼워준다.
끼우기 전의 frontNodeList 앞쪽노드가 리턴된다.
*/
struct NODE *insertNodeFront(struct NODE *targetNodeList, struct NODE *frontNodeList);
/*
back방향으로 노드를 끼워준다.
끼우기 전의 backNodeList 앞쪽노드가 리턴된다.
*/
struct NODE *insertNodeBack(struct NODE *targetNodeList, struct NODE *backNodeList);
/*
node가 몇개있는지 확인해준다.
*/
int getNodeCount(struct NODE *nodeList);
/*
노드를 잘라내기 한다.
*/
struct NODE *cutNode(struct NODE *cutNode);
/*
nodelist중에서 제일 앞의 노드를 찾아준다.
*/
struct NODE *getHeadNode(struct NODE *nodeList);
/*
nodelist중에서 제일 뒤의 노드를 찾아준다.
*/
struct NODE *getTailNode(struct NODE *nodeList);
/*
해당 노드 1개만 삭제한다.
*/
void delNode(struct NODE *targetNode);
/*
노드리스트를 삭제한다.
nodeList의 back부분은 전부 삭제하고, front부분은 연결만 끊어준다.
nodeList의 첫front부분을 리턴한다.
*/
struct NODE *delNodeList(struct NODE *nodeList);

#ifdef	__cplusplus
		}
#endif