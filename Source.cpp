#include <stdio.h>
#include <locale.h>
#include <math.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	printf("Лабораторная работа №2, вариант 7:\n\nВычислить функцию ln(1+x), |x| < 1 представленную в виде ряда Маклорена,\n"
		"с заданной точностью 0 < eps < 1 или с заданным числом членов разложения N > 10.\n\n");

	int end;
	do
	{
		double x;
		do
		{
			printf_s("Введите x = ");
			scanf_s("%lf", &x);
			if (fabs(x) >= 1)
				printf("Введеное число не удовлетворяет условию |x| < 1, повторите ввод...\n\n");
		} while (fabs(x) >= 1);

		printf("\n\nКаким способом Вы хотите вычислить функцию ln(%.16lf),\nпредставленную в виде ряда Маклорена?\n", 1.0 + x);
		printf("1) С заданной точностью 0 < eps < 1\n2) C заданным числом членов разложения N > 10\n\n");
		int ans;
		do
		{
			printf_s("Выберите вариант вычисления фунцкии (1 или 2): ");
			scanf_s("%d", &ans);
			if (ans != 1 && ans != 2)
				printf("Ввести можно только 1 или 2, повторите ввод...\n\n");
		} while (ans != 1 && ans != 2);
	
		double sum = 0.0;
		switch (ans)
		{
		case 1:
		{
			printf("\nЗаданная функция будет вычисленна с заданной точностью.\n");
			double eps;
			do
			{
				printf("Введите точность eps = ");
				scanf_s("%lf", &eps);
				if (eps <= 0.0 || eps >= 1.0)
					printf("Введеное число не удовлетворяет условию 0 < eps < 1, повторите ввод...\n\n");
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
			printf("Фунция ln(%.16lf), представленная в виде ряда Маклорена, c точностью %.16lf имеет следующий вид:\n", 1.0 + x, eps);
			break;
		}
		case 2:
		{
			printf("\nЗаданная функция будет вычисленна c заданным числом членов разложения.\n");
			int N;
			do
			{
				printf("Введите число членов разложения N = ");
				scanf_s("%d", &N);
				if (N <= 10)
					printf("Введеное число не удовлетворяет условию N > 10, повторите ввод...\n\n");
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
			printf("Фунция ln(%.16lf), представленная в виде ряда Маклорена, с числом разложений %d имеет следующий вид:\n", 1.0 + x, N);
			break;
		}
		}
		printf("%.55lf\n\n", sum);
		
		do
		{
			printf("Вы хотите продолжить работу программы с другими значениями параметров? (1 - да / 0 - нет): ");
			scanf_s("%d", &end);
			if (end != 1 && end != 0)
				printf("Ввести можно только 0 или 1, повторите ввод...\n\n");
		} while (end != 1 && end != 0);
		if (end)
			printf("\n\n\n-----------------------------------\n\n\n");
	} while (end);
	return 0;
}