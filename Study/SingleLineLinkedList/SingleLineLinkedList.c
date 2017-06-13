#include "node.h"
#include <stdio.h>
#include <time.h>

/*
1억개의 노드생성 및 개수체크하고 정상적으로 삭제한다.
단, 노드생성할때 데이터 생성은 하지 않는다.
1억개를 소화하려면 64bit에 매우 넉넉한 램용량이 필요할 것 같으며, 32bit는 메모리 할당폭이 좁아서 금방 프로그램 충돌나서 종료될것 같다.
*/
void doTest(void);
/*
1억개의 노드생성 및 dataset, 그리고 정상적으로 삭제한다.
*/
void doTest2(void);
/*
UserInterface 적용중
*/
void doTest3(void);

int main(int argc, char *args[])
{
	int sw;

	srand(time(NULL));

	do
	{
		printf(
			"What Test?\n"\
			"1. 1억개의 노드생성 및 개수체크하고 정상적으로 삭제한다.\n"\
			"2. 1억개의 노드생성 및 dataset, 그리고 정상적으로 삭제한다.\n"\
			"3. UserInterface 적용중.\n"\
			"0. 종료\n"\
			"Number>"
		);
		sw = getch();
		printf("%c\n", sw);

		switch (sw)
		{
		case '1':
			doTest();
			break;
		case '2':
			doTest2();
			break;
		case '3':
			doTest3();
			break;
		default:
			break;
		}
	} while (sw != '0');
	
	return 0;
}

void doTest3() // TODO 프로그램 부피가 커지고 같은기능 반복할 일이 생겨서 파일로 따로 쪼개야될듯, 게다가 cut을 활용한 동작 다중리스트도 해야됨.
{
	int c;
	const char *helpMessage = "q: exit, h: help, a: add, arrow: move, d: del\n";
	struct NODE *list = NULL;
	struct NODE *tail = NULL;
	struct NODE *cursor = NULL;
	struct NODE *tNode;
	int cursorPosition = 0;
	int nodeCount = 0;

	printf(helpMessage);

	do
	{
		c = getch();

#define USE_SWITCH
#ifdef USE_SWITCH // Q) SWITCH쓰는게 빠를까? if-else if-else if쓰는게 빠를까?
		switch (c)
		{
		case 'h':
		{ // Q) 왜 유독 switch만 자동정렬을 1-depth낮게 맞춰주는걸까?
			printf(helpMessage);
			break;
		}
		case 'a':
		{
			if (list != NULL)
			{
				insertNodeBack(tail, createNode(NULL));
				tail = tail->backNode;
			}
			else
			{
				list = createNode(NULL);
				tail = list;
				cursor = list;
			}

			printf("nodeCount: %d\n", ++nodeCount);
			break;
		}
		case 224: // 0xE0 // Q) 화살표 누르면 왜 이값이 튀어나오게 했을까?
		{
			switch (getch())
			{
			case 72: // up
				break;
			case 80: // down
				break;
			case 75: // left
			{
				if (cursor == NULL)
				{
					printf("nodeCount is 0\n");
					break;
				}

				if (cursor->frontNode != NULL)
				{
					cursor = cursor->frontNode;
					--cursorPosition;
				}
				
				printf("cursorPosition = %d\n", cursorPosition);
				break;
			}
			case 77: // right
			{
				if (cursor == NULL)
				{
					printf("nodeCount is 0\n");
					break;
				}

				if (cursor->backNode != NULL)
				{
					cursor = cursor->backNode;
					++cursorPosition;
				}
				
				printf("cursorPosition = %d\n", cursorPosition);
				break;
			}
			default:
			{
				break;
			}
			}

			break;
		}
		case 'd':
		{
			if (cursor == NULL)
			{
				printf("nodeCount is 0\n");
				break;
			}

			tNode = cursor;

			if (cursor->frontNode != NULL)
			{
				cursor = cursor->frontNode;
				--cursorPosition;

				if (tNode == tail)
				{
					tail = cursor;
				}
			}
			else if(cursor->backNode != NULL)
			{
				cursor = cursor->backNode;

				if (tNode == list)
				{
					list = cursor;
				}
			}
			else
			{
				cursor = NULL;
				list = NULL;
				tail = NULL;
			}

			delNode(tNode);
			--nodeCount;

			printf("cursorPosition = %d\n", cursorPosition);
			printf("nodeCount = %d\n", nodeCount); // Q) 성능적으로는 --nodeCount가 여기와야 맞긴할것같은데, 기능단위 가독성때문에 이렇게 했다고 치고 이게만약 쓸모가 많아서 여기저기 복붙되다가 몇억개가 될수도 있는데 괜찮을까?
			
			break;
		}
		default:
		{
			break;
		}
		}
#else
		// 여긴 코드가 없어요.
#endif

	} while (c != 'q');

	if (list != NULL)
	{
		delNodeList(list);
	}
}

void doTest2()
{
	struct NODE *nodeList;
	struct NODE *pNode;
	char *data;
	char buf[255];
	int i;
	
	// create list

	printf("Creating list\n");

	sprintf(buf, "%06d한국어", rand());
	nodeList = createNode(buf);
	
	for (i = 0; i < 100000000; i++)
	{
		sprintf(buf, "%06d한국어", rand());
		insertNodeBack(nodeList, createNode(buf));
	}

	// print list

	printf("Will print list\n");
	
	for (pNode = nodeList; pNode != NULL; pNode = pNode->backNode)
	{
		data = getNodeData(pNode);
		//printf("%s\n", data);
	}

	// delete list

	printf("Deleting list\n");

	delNodeList(nodeList);
}

void doTest()
{
	struct NODE *ls;
	int cnt;
	int nodeCount;

	// 리스트 생성

	printf("리스트 생성중\n");

	ls = createNode(NULL);
	for (cnt = 1; cnt < 100000000; cnt++)
	{
		insertNodeBack(ls, createNode(NULL));
	}

	printf("리스트 생성완료\n");

	// 리스트의 노드개수 확인

	printf("리스트의 노드개수 확인중\n");

	nodeCount = getNodeCount(ls);
	printf("nodeCount: %d\n", nodeCount);

	// 리스트 삭제

	printf("리스트 삭제중\n");
	delNodeList(ls);

	printf("리스트 삭제완료\n");
}
