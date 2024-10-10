#include<cstdio>

int main(int argc, char* argv[])
{
	int n = 0;
	scanf_s("%d", &n);

	int a[100] = { 0 };

	for (int i = 0; i < n; ++i)
	{
		scanf_s("%d", a + i);
	}
	
	int height = 0;
	scanf_s("%d", &height);

	for (int i = 0; i < n; ++i)
	{
		if (height > a[i])
		{
			printf("%d", ++i);
			return 0;
		}

	}
	printf("%d", n + 1);

	return 0;
}