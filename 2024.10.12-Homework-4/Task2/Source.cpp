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

	int start = 1; 
	int end = 1;
	scanf_s("%d %d", &start, &end);

	int max = a[start - 1];
	int ind = start;
	for (int i = --start; i < end; ++i)
	{
		if (a[i] > max)
		{
			max = a[i];
			ind = i + 1;
		}
	}
	printf("%d %d", max, ind);


	return 0;
}