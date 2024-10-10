#include <cstdio>
#include <cmath>

int main(int argc, char* argv[])
{
	int n = 0;
	int a[1000] = { 0 };

	scanf_s("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf_s("%d", a + i);
	}

	int x = 0;
	scanf_s("%d", &x);

	int mindif = abs(a[0]-x);
	int nearestNum = a[0];
	for (int i = 0; i < n; ++i)
	{
		int dif = abs(a[i] - x);
		if (dif < mindif || dif == mindif && a[i] < nearestNum)
		{
			nearestNum = a[i];	
			mindif = abs(a[i] - x);
		}
		
	}
	printf("%d", nearestNum);

	return 0;
}