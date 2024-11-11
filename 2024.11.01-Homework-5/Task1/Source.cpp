#include <iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	
	int* array = new int[n];

	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(array + i);
	}
	
	int k = 0;
	for (; k < n; ++k)
	{
		if (*(array + k) == 1) break;
	}
	

	for (int i = 0; i < n; ++i)
	{
		std::cout << *(array + (k + i) % n) << " ";
	}
	

	delete[] array;


	return EXIT_SUCCESS;
}