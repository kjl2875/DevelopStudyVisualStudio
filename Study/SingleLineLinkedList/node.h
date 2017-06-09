#pragma once

#include <string.h>

struct NODE_DATA {
	// TODO 현재 data에 대한 계획이 없어서 계획이 필요하고, 현재는 string처럼 사용하고 있음.
	char *message;
};

struct NODE_LIST {
	struct NODE_DATA data;

	struct NODE_LIST *frontNode;
	struct NODE_LIST *backNode;
};

/*
초기화된 새 노드를 초기화된 값으로 만들어준다.(메모리할당)
*/
struct NODE_LIST *createNode(const char *message);
/*
front방향으로 노드를 끼워준다.
끼우기 전의 frontNodeList 앞쪽노드가 리턴된다.
*/
struct NODE_LIST *insertNodeFront(struct NODE_LIST *targetNodeList, struct NODE_LIST *frontNodeList);
/*
back방향으로 노드를 끼워준다.
끼우기 전의 backNodeList 앞쪽노드가 리턴된다.
*/
struct NODE_LIST *insertNodeBack(struct NODE_LIST *targetNodeList, struct NODE_LIST *backNodeList);
/*
node가 몇개있는지 확인해준다.
*/
int getNodeCount(struct NODE_LIST *nodeList);
/*
노드데이터를 설정한다.
*/
void setNodeData(struct NODE_LIST *targetNode, const char *message);
/*
노드데이터를 삭제한다.
*/
void delNodeData(struct NODE_LIST *targetNode);
/*
노드를 잘라내기 한다.
*/
struct NODE_LIST *cutNode(struct NODE_LIST *cutNode);
/*
nodelist중에서 제일 앞의 노드를 찾아준다.
*/
struct NODE_LIST *getHeadNode(struct NODE_LIST *nodeList);
/*
nodelist중에서 제일 뒤의 노드를 찾아준다.
*/
struct NODE_LIST *getTailNode(struct NODE_LIST *nodeList);
/*
노드데이터 출력값을 얻는다.
*/
const char *getNodeData(struct NODE_LIST *targetNode);
/*
해당 노드 1개만 삭제한다.
*/
void delNode(struct NODE_LIST *targetNode);
/*
노드리스트를 삭제한다.
nodeList의 back부분은 전부 삭제하고, front부분은 연결만 끊어준다.
nodeList의 첫front부분을 리턴한다.
*/
struct NODE_LIST *delNodeList(struct NODE_LIST *nodeList);
