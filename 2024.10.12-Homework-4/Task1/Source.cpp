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
	
	int compnum = 0;
	scanf_s("%d", &compnum);

	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (compnum == a[i])
		{
			++count;
		}
	}
	printf("%d", count);

	return 0;
}