#include <iostream>
#include <cmath>
#include <vector>

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
    int n = 10001000;

    std::vector<int> erato = a.generatePrimesEratosthenes(n);
    std::vector<int> eratoend(erato.end() - 1000, erato.end());
    print(eratoend);

    return 0;
}