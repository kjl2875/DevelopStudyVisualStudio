#include <stdio.h>

// http://kin.naver.com/qna/answer.nhn?dirId=1040101&docId=278749782&mdu=KxtlFqMXKqbmaAbwKVvZFq2XFAvXaAUG1rGnKo2XFL0EEkuXkkp1xAFFFkpx
// �ҵ���ؿ� ���� ������ ���ݰ��
// TODO ���۰���

int main(int argc, char *args[])
{
	double tax = 0;

	// cost = �ҵ�

	int cost;

	printf("�ҵ�ݾ�>");
	scanf("%d", &cost); // ����, �ڿ����� �Է��ؾ��� ���������� ������.
	printf("�ҵ�ݾ�=%d\n", cost);

	// 1000���� ����

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

	// 1000���� �ʰ�, 4000���� ����

	if (cost > 0)
	{
		if (cost <= 30000000) // ������ �̹� 1000���� ���� �̷�
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

	// 4000���� �ʰ�, 8000���� ����

	if (cost > 0)
	{
		if (cost <= 40000000) // ������ �̹� 4000���� ���� �̷�
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

	// 8000���� �ʰ�

	if (cost > 0)
	{
		tax += cost * 35 / 100.0;
	}

	// print.tax

	printf("tax=%lf\n", tax);
}
