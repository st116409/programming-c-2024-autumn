#include <iostream>
#include <cmath>
int main(int argc, char* argv[])
{
	int array[100] = { 0 };
	int n = 0;
	std::cin >> n;

	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(array + i);
	}

	int summ = 0;
	for (int i = 0; i < n; ++i)
	{
		if (*(array + i) > 0) {
			summ += *(array + i);
		}
	}
	
	int minx = *array;
	int imin = 0;
	for (int i = 0; i < n; ++i)
	{
		if (minx > *(array + i))
		{
			minx = *(array + i);
			imin = i;
		}
	}
	
	int maxx = *array;
	int imax = 0;
	for (int i = 0; i < n; ++i)
	{
		if (maxx < *(array + i))
		{
			maxx = *(array + i);
			imax = i;
		}
	}
	int x = std::min(imin, imax);
	int y = std::max(imin, imax);
	
	int prod = 1;
	for (int i = ++x; i < y; ++i)
	{
		prod *= *(array + i);
	}
	std::cout << summ << " " << prod;

	return EXIT_SUCCESS;
}