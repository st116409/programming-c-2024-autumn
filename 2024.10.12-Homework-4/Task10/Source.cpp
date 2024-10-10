#include<cstdio>

int main(int argc, char* argv[])
{
	int n = 0;
	scanf_s("%d", &n);

	int a[1000] = { 0 };

	for (int i = 0; i < n; ++i)
	{
		a[i] = i + 1;
	}

	int start1 = 0;
	int end1 = 0;
	int start2 = 0;
	int end2 = 0;

	scanf_s("%d %d %d %d", &start1, &end1, &start2, &end2);

	int b[1000] = { 0 };
	for (int i = 0; i < end1 - start1 + 1; ++i)
	{
		b[i] = a[end1 - i - 1];
	}

	for (int i = 0; i < end1 - start1 + 1; ++i)
	{
		a[start1 + i - 1] = b[i];

	}

	int c[1000] = { 0 };
	for (int i = 0; i < end2 - start2 + 1; ++i)
	{
		c[i] = a[end2 - i - 1];
	}

	for (int i = 0; i < end2 - start2 + 1; ++i)
	{
		a[start2 + i - 1] = c[i];
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	
	return 0;
}