#include <stdio.h>

// http://kin.naver.com/qna/detail.nhn?d1id=1&dirId=1040101&docId=278978669

int main(int argc, char *args[])
{
	int sum = 0;
	int n, m, mFlag; // number, memory, minus-flag

	for (n = 1, mFlag = 0; n <= 100; n++)
	{
		m = n * n;

		if (mFlag == 0)
		{
			printf("-%d", m);
			sum += m * -1;

			mFlag = 1;
		}
		else
		{
			printf("+%d", m);
			sum += m * 1;

			mFlag = 0;
		}
	}

	printf(" = %d\n", sum);

	return 0;
}
