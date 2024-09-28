#include<cstdio>
#include<cstdlib>


int main(int argc, char* argv[])
{
	int x1 = 0;
	int y1 = 0;
	int r1 = 0;
	int x2 = 0;
	int y2 = 0;
	int r2 = 0;

	scanf_s("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
	
	int dsq = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2); // the square of the distance
	int rsum = (r1 + r2) * (r1 + r2); // the square of the summ of the radii

	if (rsum >= dsq && (r1 - r2) * (r1 - r2) <= dsq)
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}



	return EXIT_SUCCESS;
}