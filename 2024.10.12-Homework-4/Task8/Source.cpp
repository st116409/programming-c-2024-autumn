#include<cstdio>

int main(int argc, char* argv[])
{
	int n = 0;
	scanf_s("%d", &n);

	int a[1000] = { 0 };

	for (int i = 0; i < n; ++i)
	{
		scanf_s("%d", a + i);
	}
	
	int m = 0;
	scanf_s("%d", &m);

	for (int i = 0; i < m; ++i)
	{
		int start = 0;
		int end = 0;
		scanf_s("%d %d", &start, &end);

		for (int j = --start; j < end; ++j)
		{
			printf("%d ", a[j]);
		}
		printf("\n");
	}
	
	
	return 0;
}