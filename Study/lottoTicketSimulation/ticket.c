#include "ticket.h"
#include <stdio.h>
#include <stdlib.h>

struct TICKET getTicket()
{
	struct TICKET ticket;
	int i, k, m, m2, ls[NUM_MAX];

	for (i = 1; i <= NUM_MAX; i++)
	{
		ls[i - 1] = i;
	}
	
	for (i = 0; i < NUM_CNT; i++)
	{
		m = 45 - i;
		m2 = m - 1;
		k = rand() % m;
		ticket.n[i] = ls[k];
		
		if (k < m2)
		{
			swap(&ls[k], &ls[m2]);
		}
	}

	sortBubble(ticket.n, NUM_CNT);

	return ticket;
}

// TODO sortBubble method is not working now.

void sortBubble(int *res, const int cnt) // resource, count
{
	int roof;

	int i; // index
	int max;

	for (roof = 0; roof < cnt; roof++)
	{
		max = cnt - roof - 1;
		for (i = 0; i < max; i++)
		{
			if (res[i] > res[i + 1])
			{
				swap(&res[i],&res[i+1]);
			}
		}
	}

}

void swap(int *a, int *b)
{
	int m;
	m = *a;
	*a = *b;
	*b = m;
}

void printTicket(struct TICKET *ticket)
{
	int i = 0;
	const int l = NUM_CNT - 1;

	while(1)
	{
		printf("%02d", ticket->n[i]);
		if (i == l)
		{
			break;
		}
		putchar(' ');

		i++;
	}
	
}

int getBonusNumber(const struct TICKET ticket)
{
	int i;
	int bn; // bonus number

	while (1)
	{
		bn = (rand() % NUM_MAX) + 1;

		for (i = 0; i < NUM_CNT; i++)
		{
			if (ticket.n[i] != bn)
			{
				break;
			}
		}

		if (bn == NUM_CNT)
		{
			break;
		}
	}
	
	return bn;
}

int hit(const struct TICKET result, const int bonusNumber, const struct TICKET ticket)
{
	int i, j;
	int c = 0;

	for (i = 0; i < NUM_CNT; i++)
	{
		for (j = 0; j < NUM_CNT; j++)
		{
			if (result.n[i] == ticket.n[j])
			{
				c++;
				break;
			}
		}
	}

	if (c == 5)
	{
		for (i = 0; i < NUM_CNT; i++)
		{
			if (result.n[i] == bonusNumber)
			{
				c = 7;
				break;
			}
		}
	}

	return c;
}

void printResult(long long count, const int *hitCountResult)
{
	// print count

	printf("count: ");
	printNumber(count);
	printf("\n");


	// print stat

	printf("--------------일치통계--------------\n");
	printf("0개 일치        : "); printNumberInt(hitCountResult[0]); printf("\n");
	printf("1개 일치        : "); printNumberInt(hitCountResult[1]); printf("\n");
	printf("2개 일치        : "); printNumberInt(hitCountResult[2]); printf("\n");
	printf("3개 일치        : "); printNumberInt(hitCountResult[3]); printf("\n");
	printf("4개 일치        : "); printNumberInt(hitCountResult[4]); printf("\n");
	printf("5개 일치        : "); printNumberInt(hitCountResult[5]); printf("\n");
	printf("6개 일치        : "); printNumberInt(hitCountResult[6]); printf("\n");
	printf("5개+보너스 일치 : "); printNumberInt(hitCountResult[7]); printf("\n");
	printf("\n");
}

void printNumberInt(int n)
{
	long long x = n;
	printNumber(x);
}

void printNumber(long long n)
{
	int i = 0;
	int ary[10] = { 0, };

	while (n > 0)
	{
		ary[i++] = n % 1000;
		n = n / 1000;
	}

	printf("%d,", ary[--i]);
	while (i > 0)
	{
		printf("%03d,", ary[--i]);
	}
	printf("%03d", ary[i]);
}
