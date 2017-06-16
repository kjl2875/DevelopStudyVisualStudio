#pragma once

struct NODE_DATA {
	// TODO 현재 data에 대한 계획이 없어서 계획이 필요하고, 현재는 string처럼 사용하고 있음.
	char *message;
};

/*
노드데이터 출력값을 얻는다.
*/
const char *getNodeData(struct NODE_DATA *nodeData);
/*
노드데이터를 삭제한다.
*/
void delNodeData(struct NODE_DATA *nodeData);
/*
노드데이터를 설정한다.
*/
void setNodeData(struct NODE_DATA *nodeData, const char *message);

