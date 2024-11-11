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
	std::cin >> k;
	
	for (int i = 0; i < n; ++i)
	{
		std::cout << *(array + (n - k % n + i) % n) << " ";
	}
	
	delete[] array;

	return EXIT_SUCCESS;
}