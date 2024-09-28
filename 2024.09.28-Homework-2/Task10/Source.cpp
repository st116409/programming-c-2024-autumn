#include<cstdio>
#include<cstdlib>


int main(int argc, char* argv[])
{
	int cost = 0;
	int cat = 0;
	int fox = 0;
	scanf_s("%d", &cost);

	int mod = cost % 5;

	switch (mod) 
	{
	case 1:
		cat = cost / 5 - 1;
		fox = 2;
		break;
	case 2:
		cat = cost / 5 - 2;
		fox = 4;
		break;
	case 3:
		cat = cost / 5;
		fox = 1;
		break;
	case 4:
		cat = cost / 5 - 1;
		fox = 3;
		break;
	default:
		cat = cost / 5;
		break;
	}
	printf("%d %d", cat, fox);


	return EXIT_SUCCESS;
}