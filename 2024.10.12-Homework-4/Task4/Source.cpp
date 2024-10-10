#include<cstdio>

int main(int argc, char* argv[])
{
	int n = 0;
	int a[1000] = { 0 };

	scanf_s("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf_s("%d", a + i);
	}

	int max = 0;

	for (int i = 0; i < n; ++i)
	{
		int harvest = a[i] + a[(i + 1) % n] + a[(i + 2) % n];
		if (harvest > max)
		{
			max = harvest;
		}
	}
	printf("%d", max);


	return 0;
}