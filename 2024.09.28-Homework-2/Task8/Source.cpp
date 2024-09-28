#include<iostream>
#include<cstdio>

int main(int argc, char* argv[])
{
	int m = 0;
	int n = 0;

	scanf_s("%d %d", &m, &n);
	int str = 0;
	
	if (m == 1 || n == 1)
	{
		str = (n + 1) * m + (m + 1) * n + (m - 1) * n + (n - 1) * m;
	}
	else
	{
		str = (n + 1)* m + (m + 1) * n + 2 * (n / 2) + 2 * (m / 2) + (n % 2 + m % 2) % 2;
	}
	printf("%d", str);

	return EXIT_SUCCESS;
}