#include<cstdio>

int main(int argc, char* argv[])
{
	int n = 0;
	scanf_s("%d", &n);

	int corp[100] = { 0 };
	int taxes[100] = { 0 };

	for (int i = 0; i < n; ++i)
	{
		scanf_s("%d", corp + i);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf_s("%d", taxes + i);
	}

	int maxtax = 0;
	int ind = 1;
	for (int i = 0; i < n; ++i)
	{
		int tax = corp[i] * taxes[i]; 
		if (tax > maxtax)
		{
			maxtax = tax;
			ind = i + 1;
		}
	}
	printf("%d", ind);
	
	return 0;
}