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

	// ��÷��ȣ �����

	resultTicket = getTicket(); // ��÷��ȣ �����
	bonusNumber = getBonusNumber(resultTicket); // ���� ��÷��ȣ�� �ߺ����� �ʴ� ���ʽ���ȣ �����
	printTicket(&resultTicket); // printf
	printf("(%d)\n", bonusNumber);

	// �ߴ��Ҷ����� ������ ��ȣ�̾Ƴ���

	printf("�ùķ����� ����. �ƹ�Ű�� ������ ������� ������, x�� ������ ����˴ϴ�.\n");

	c = 0;
	while (1)
	{
		++c;

		ticket = getTicket();
		//printticket(&ticket);
		//putchar('\n');

		hc = hit(resultTicket, bonusNumber, ticket); // ��÷��ȣ�� ��
		//printf("%d ", hc);

		++hcl[hc]; // ��迡 �ݿ�

		if (kbhit())
		{
			printResult(c, hcl); // ������

			if (getch() == 'x' || getch() == 'X')
			{
				break;
			}
		}
	}

	//putchar('\n');
}