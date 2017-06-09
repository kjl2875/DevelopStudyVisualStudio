#include "node.h"
#include <stdio.h>

int main(int argc, char *args[])
{
	struct NODE_LIST *ls = createNode();
	int cnt;
	int nodeCount;

	for (cnt = 0; cnt < 100000000; cnt++)
	{
		insertNodeBack(ls, createNode());
	}

	nodeCount = getNodeCount(ls);
	printf("nodeCount: %d\n", nodeCount);
}
