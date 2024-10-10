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

	for (int i = n; i > 0; --i)
	{
		printf("%d ", a[i-1]);
	}

	return 0;
}