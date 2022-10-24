#include <iostream>
#include <cmath>

int main()
{
    int sumsquares = 0, squaressum = 0;
    for (int i = 1; i <= 100; ++i)
    {
        sumsquares += std::pow(i, 2);
    }
    for (int i = 1; i <= 100; ++i)
    {
        squaressum += i;
    }
    squaressum = std::pow(squaressum, 2);
    std::cout << squaressum - sumsquares << std::endl;
    return 0;
}