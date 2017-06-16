#include "nodedata.h"
#include <stdio.h>
#include <stdarg.h>

void setNodeData(struct NODE_DATA *nodeData, const char *message)
{
	// ���� �Ҵ�� �޸� ����

	if (nodeData->message != NULL)
	{
		free(nodeData->message);
	}

	// �ű� �޸� �Ҵ�

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
		// �Ҵ������ϰ� NULL�� �ǵ�����.

		free(nodeData->message);
		nodeData->message = NULL;
	}
}

const char *getNodeData(struct NODE_DATA *nodeData)
{
	return nodeData->message;
}
