#pragma once

struct NODE_DATA {
	// TODO ���� data�� ���� ��ȹ�� ��� ��ȹ�� �ʿ��ϰ�, ����� stringó�� ����ϰ� ����.
	char *message;
};

/*
��嵥���� ��°��� ��´�.
*/
const char *getNodeData(struct NODE_DATA *nodeData);
/*
��嵥���͸� �����Ѵ�.
*/
void delNodeData(struct NODE_DATA *nodeData);
/*
��嵥���͸� �����Ѵ�.
*/
void setNodeData(struct NODE_DATA *nodeData, const char *message);

