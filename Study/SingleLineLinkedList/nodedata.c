#include "nodedata.h"
#include <stdio.h>
#include <stdarg.h>

void setNodeData(struct NODE_DATA *nodeData, const char *message)
{
	// 기존 할당된 메모리 해제

	if (nodeData->message != NULL)
	{
		free(nodeData->message);
	}

	// 신규 메모리 할당

	if (message == NULL)
	{
		nodeData->message = NULL;
	}
	else
	{
		nodeData->message = malloc(sizeof(char) * (strlen(message)));
		strcpy(nodeData->message, message);
	}
}

void delNodeData(struct NODE_DATA *nodeData)
{
	if (nodeData->message != NULL)
	{
		// 할당해제하고 NULL로 되돌린다.

		free(nodeData->message);
		nodeData->message = NULL;
	}
}

const char *getNodeData(struct NODE_DATA *nodeData)
{
	return nodeData->message;
}
