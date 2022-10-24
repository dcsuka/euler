#include <iostream>
#include <cmath>
#include <vector>

class Solution
{
public:
    long largestPrimeFactor(const long &n)
    {
        int a = 2;
        while (true)
        {
            if (!(n % a))
            {
                long maybe = n / a;
                long lim = std::pow(maybe, 0.5);
                int i = 2;
                for (; i <= lim; ++i)
                {
                    if (!(maybe % i))
                    {
                        break;
                    }
                    if (i == lim)
                        return maybe;
                }
            }
            ++a;
        }
        return 0;
    }
};

int main()
{
    Solution a;
    long n = 600851475143;

    long result = a.largestPrimeFactor(n);

    std::cout << "Largest prime factor of " << n << ":" << std::endl
              << std::endl;

    std::cout << "Result: " << result << std::endl;

    return 0;
}