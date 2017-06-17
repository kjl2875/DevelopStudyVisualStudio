#include <stdio.h>

// http://kin.naver.com/qna/answer.nhn?dirId=1040101&docId=278749782&mdu=KxtlFqMXKqbmaAbwKVvZFq2XFAvXaAUG1rGnKo2XFL0EEkuXkkp1xAFFFkpx
// 소득기준에 따른 차감형 세금계산
// TODO 동작검증

int main(int argc, char *args[])
{
	double tax = 0;

	// cost = 소득

	int cost;

	printf("소득금액>");
	scanf("%d", &cost); // 주의, 자연수만 입력해야지 정상적으로 동작함.
	printf("소득금액=%d\n", cost);

	// 1000만원 이하

	if (cost > 0)
	{
		if (cost <= 10000000)
		{
			tax += cost * 8 / 100.0;
			cost = 0;
		}
		else
		{
			tax += 10000000 * 8 / 100.0;
			cost -= 10000000;
		}
	}

	// 1000만원 초과, 4000만원 이하

	if (cost > 0)
	{
		if (cost <= 30000000) // 앞전에 이미 1000만원 빼서 이럼
		{
			tax += cost * 17 / 100.0;
			cost = 0;
		}
		else
		{
			tax += 30000000 * 17 / 100.0;
			cost -= 30000000;
		}
	}

	// 4000만원 초과, 8000만원 이하

	if (cost > 0)
	{
		if (cost <= 40000000) // 앞전에 이미 4000만원 빼서 이럼
		{
			tax += cost * 26 / 100.0;
			cost = 0;
		}
		else
		{
			tax += 40000000 * 26 / 100.0;
			cost -= 40000000;
		}
	}

	// 8000만원 초과

	if (cost > 0)
	{
		tax += cost * 35 / 100.0;
	}

	// print.tax

	printf("tax=%lf\n", tax);
}
