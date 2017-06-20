#pragma once

/**
 *
 * ticket.h
 * require before srand(v) run it in stdlib.h
 *
 */

#define NUM_MAX (45)
#define NUM_CNT (6)

struct TICKET
{
	int n[NUM_CNT];
};

struct TICKET getTicket(void);
void sortBubble(int *res, const int cnt);
void swap(int *a, int *b);
void printNumber(long long n);
void printNumberInt(int n);
void printTicket(struct TICKET *ticket);
int getBonusNumber(const struct TICKET ticket);

/**
 *
 * hit() ��Ȱ� ��
 * result: ���
 * bonusNumber: ���ʽ� ��ȣ
 * ticket: every ticket
 *
 * @return: 0~6=match count, 7=5+bounus
 */
int hit(const struct TICKET result, const int bonusNumber, const struct TICKET ticket);

/**
 *
 * printResult()
 * count: just ticket count
 * hitCountResult[return value of hit() method]
 *
 */
void printResult(long long count, const int *hitCountResult);

