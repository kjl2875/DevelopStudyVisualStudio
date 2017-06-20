#include "ticket.h"

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void run();
void bonusNumberHitTest();

int main(int argc, char **args)
{
	run();
	//bonusNumberHitTest();

	return 0;
}

void bonusNumberHitTest()
{
	struct TICKET ticket;
	struct TICKET resultTicket;
	int bonusNumber;
	int r;

	resultTicket.n[0] = 7;
	resultTicket.n[1] = 14;
	resultTicket.n[2] = 22;
	resultTicket.n[3] = 28;
	resultTicket.n[4] = 33;
	resultTicket.n[5] = 39;
	bonusNumber = 6;

	ticket.n[0] = 7;
	ticket.n[1] = 14;
	ticket.n[2] = 20;
	ticket.n[3] = 28;
	ticket.n[4] = 33;
	ticket.n[5] = 39;

	while (1)
	{
		r = hit(resultTicket, bonusNumber, ticket);
		printf("%d\n", r);
		getchar();
	}
}

void run()
{
	long long c; // counter
	struct TICKET ticket;
	struct TICKET resultTicket;
	int bonusNumber;
	int hc; // hit count
	int hcl[8] = { 0, }; // hit count list

	srand(time(NULL));

	// 당첨번호 만들기

	resultTicket = getTicket(); // 당첨번호 만들기
	bonusNumber = getBonusNumber(resultTicket); // 기존 당첨번호와 중복되지 않는 보너스번호 만들기
	printTicket(&resultTicket); // printf
	printf("(%d)\n", bonusNumber);

	// 중단할때까지 무한정 번호뽑아내기

	printf("시뮬레이터 시작. 아무키나 누르면 결과값이 나오고, x를 누르면 종료됩니다.\n");

	c = 0;
	while (1)
	{
		++c;

		ticket = getTicket();
		//printticket(&ticket);
		//putchar('\n');

		hc = hit(resultTicket, bonusNumber, ticket); // 당첨번호와 비교
		//printf("%d ", hc);

		++hcl[hc]; // 통계에 반영

		if (kbhit())
		{
			printResult(c, hcl); // 통계출력

			if (getch() == 'x' || getch() == 'X')
			{
				break;
			}
		}
	}

	//putchar('\n');
}