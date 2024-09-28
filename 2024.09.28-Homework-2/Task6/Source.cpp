#include<iostream>
#include<cmath>

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int c = 0;
	scanf_s("%d %d %d", &a, &b, &c);

	long long d = b * b - 4 * a * c;

	if (a == 0 && b == 0 && c == 0)
	{
		printf_s("-1");
	}
	else if (a == 0 && b == 0)
	{
		printf("0");
	}
	else if (a == 0)
	{
		double x = -c / (b * 1.0);
		printf("1\n");
		printf("%.6lf", x);
	}
	else
	{
		if (d < 0)
		{
			printf("0");
		}
		else if (d == 0)
		{
			double x = -b / (2.0 * a);
			printf("1\n");
			printf("%.6lf\n", x);
		}
		else
		{
			double x1 = (-b - sqrtf(d)) / (2.0 * a);
			double x2 = (-b + sqrtf(d)) / (2.0 * a);
			printf("2\n");
			printf("%.6lf\n", x1);
			printf("%.6lf\n", x2);
		}
	}
	return EXIT_SUCCESS;
}