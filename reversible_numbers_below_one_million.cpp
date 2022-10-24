#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <chrono>

class Solution
{
public:
    std::vector<int> odds{'0', '2', '4', '6', '8'};

    int reverseNumber(int n)
    {
        int ret = 0;
        while (n)
        {
            ret *= 10;
            ret += n % 10;
            n /= 10;
        }
        return ret;
    }

    bool isReversible(int n)
    {
        if (!(n % 10))
            return false;
        std::string mystring = std::to_string(n + reverseNumber(n));
        std::sort(mystring.begin(), mystring.end());
        std::vector<char> ret;
        std::set_intersection(mystring.begin(), mystring.end(), odds.begin(), odds.end(), std::back_inserter(ret));
        return ret.empty();
    }
    int reversibleRange(const int &n)
    {
        int count = 0;
        for (int i = 1; i < n; ++i)
        {
            if (isReversible(i))
                ++count;
        }
        return count;
    }
};

int main()
{
    Solution a;
    int n = 1000000000;
    auto start = std::chrono::high_resolution_clock::now();
    int res = a.reversibleRange(n);
    auto stop = std::chrono::high_resolution_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::minutes>(stop - start);
    std::cout << "Reversible numbers up to " << n << ": " << res << std::endl;
    std::cout << "Time in minutes: " << time.count() << std::endl;
    return 0;
}