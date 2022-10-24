#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>
#include <chrono>

template <typename T>
void print(const std::vector<T> &myT)
{
    for (auto x : myT)
        std::cout << x << " ";
    std::cout << std::endl;
}

class Solution
{
public:
    std::vector<int> generatePrimesLoop(const int &n)
    {
        std::vector<int> ret;
        std::vector<bool> notprimes(n + 1, false);
        for (int i = 2; i <= n; ++i)
        {
            int lim = std::pow(i, 0.5);
            for (int div = 2; div <= lim; ++div)
            {
                if (!(i % div))
                {
                    notprimes[i] = true;
                }
            }
        }
        for (int i = 2; i <= n; ++i)
        {
            if (!(notprimes[i]))
                ret.emplace_back(i);
        }
        return ret;
    }

    std::vector<int> generatePrimesEratosthenes(const int &n)
    {
        std::vector<int> ret;
        std::vector<bool> notprimes(n + 1, false);
        for (int i = 2; i <= std::pow(n, 0.5); ++i)
        {
            if (notprimes[i])
                continue;
            for (int j = std::pow(i, 2); j <= n; j += i)
            {
                notprimes[j] = true;
            }
        }
        for (int x = 2; x <= n; ++x)
        {
            if (!notprimes[x])
                ret.emplace_back(x);
        }
        return ret;
    }
};

int main()
{
    Solution a;
    int n = 1000000;

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> erato = a.generatePrimesEratosthenes(n);
    auto stop = std::chrono::high_resolution_clock::now();
    auto eratoDuration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Benchmarks for generation of " << n << " prime numbers in microseconds:" << std::endl;
    std::cout << "Sieve of Eratosthenes: " << eratoDuration.count() << std::endl;

    start = std::chrono::high_resolution_clock::now();
    std::vector<int> loop = a.generatePrimesLoop(n);
    stop = std::chrono::high_resolution_clock::now();
    auto loopDuration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "For loop: " << loopDuration.count() << std::endl;

    assert(erato == loop);

    return 0;
}