#include <iostream>

int main(int argc, char* argv[])
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    int n = 0;
    std::cin >> n;
    int m = 0;
    std::cin >> m;
    int array[100001] = { 0 };
    int x = 0;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> x;
        array[x] = 1;
    }
    for (int i = 0; i < m; ++i)
    {
        std::cin >> x;
        if (array[x] == 1) array[x] = 2;
    }
    for (int i = 0; i < 100001; ++i)
    {
        if (array[i] == 2) std::cout << i << " ";
    }

    return EXIT_SUCCESS;
}