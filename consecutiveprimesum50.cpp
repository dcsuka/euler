#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_set>

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

bool Compare(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
    return a.second < b.second;
}

int main()
{
    Solution a;

    int n = 1000000;
    std::vector<int> erato = a.generatePrimesEratosthenes(n);

    std::unordered_set<int> primes(erato.begin(), erato.end());
    std::vector<std::pair<int, int>> maxcounts;

    for (int x = 0; x < 10000; ++x)
    {
        int maxcount = 0;
        int maxtime = 0;
        int count = 0;
        for (int i = x, times = 0; i < erato.size() && count < 1000000; ++i, ++times)
        {
            count += erato[i];
            if (primes.find(count) != primes.end())
            {
                maxcount = count;
                maxtime = times;
            }
        }
        maxcounts.push_back(std::pair(maxcount, maxtime));
    }
    auto result = std::max_element(maxcounts.begin(), maxcounts.end(), Compare);
    std::cout << result->first << " " << result->second << std::endl;
    return 0;
}