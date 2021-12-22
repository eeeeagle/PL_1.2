#include <stdio.h>
#include <locale.h>
#include <math.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	printf("������������ ������ �2, ������� 7:\n\n��������� ������� ln(1+x), |x| < 1 �������������� � ���� ���� ���������,\n"
		"� �������� ��������� 0 < eps < 1 ��� � �������� ������ ������ ���������� N > 10.\n\n");

	int end;
	do
	{
		double x;
		do
		{
			printf_s("������� x = ");
			scanf_s("%lf", &x);
			if (fabs(x) >= 1)
				printf("�������� ����� �� ������������� ������� |x| < 1, ��������� ����...\n\n");
		} while (fabs(x) >= 1);

		printf("\n\n����� �������� �� ������ ��������� ������� ln(%.16lf),\n�������������� � ���� ���� ���������?\n", 1.0 + x);
		printf("1) � �������� ��������� 0 < eps < 1\n2) C �������� ������ ������ ���������� N > 10\n\n");
		int ans;
		do
		{
			printf_s("�������� ������� ���������� ������� (1 ��� 2): ");
			scanf_s("%d", &ans);
			if (ans != 1 && ans != 2)
				printf("������ ����� ������ 1 ��� 2, ��������� ����...\n\n");
		} while (ans != 1 && ans != 2);
	
		double sum = 0.0;
		switch (ans)
		{
		case 1:
		{
			printf("\n�������� ������� ����� ���������� � �������� ���������.\n");
			double eps;
			do
			{
				printf("������� �������� eps = ");
				scanf_s("%lf", &eps);
				if (eps <= 0.0 || eps >= 1.0)
					printf("�������� ����� �� ������������� ������� 0 < eps < 1, ��������� ����...\n\n");
			} while (eps <= 0.0 || eps >= 1.0);

			double res = 0.0, prev = 1.0, prevx = 1.0;
			for (int n = 1; fabs(prev - res) > eps; n++)
			{
				prev = res;
				res = prevx * x / n;
				if (n % 2 == 0)
					res = -res;
				sum += res;
				prevx *= x;
			}
			printf("������ ln(%.16lf), �������������� � ���� ���� ���������, c ��������� %.16lf ����� ��������� ���:\n", 1.0 + x, eps);
			break;
		}
		case 2:
		{
			printf("\n�������� ������� ����� ���������� c �������� ������ ������ ����������.\n");
			int N;
			do
			{
				printf("������� ����� ������ ���������� N = ");
				scanf_s("%d", &N);
				if (N <= 10)
					printf("�������� ����� �� ������������� ������� N > 10, ��������� ����...\n\n");
			} while (N <= 10);
						
			double res = 0.0, prev = 1.0, prevx = 1.0;
			for (int n = 1; n <= N; n++)
			{
				prev = res;
				res = prevx * x / n;
				if (n % 2 == 0)
					res = -res;
				sum += res;
				prevx *= x;
			}
			printf("������ ln(%.16lf), �������������� � ���� ���� ���������, � ������ ���������� %d ����� ��������� ���:\n", 1.0 + x, N);
			break;
		}
		}
		printf("%.55lf\n\n", sum);
		
		do
		{
			printf("�� ������ ���������� ������ ��������� � ������� ���������� ����������? (1 - �� / 0 - ���): ");
			scanf_s("%d", &end);
			if (end != 1 && end != 0)
				printf("������ ����� ������ 0 ��� 1, ��������� ����...\n\n");
		} while (end != 1 && end != 0);
		if (end)
			printf("\n\n\n-----------------------------------\n\n\n");
	} while (end);
	return 0;
}