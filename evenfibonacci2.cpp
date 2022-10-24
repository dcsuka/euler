#include <iostream>

int main()
{
    int ret = 0;
    int prevprev = 0, prev = 1, curr = 0;
    while (curr < 4000000)
    {
        curr = prev + prevprev;
        if (!(curr & 1))
            ret += curr;
        prevprev = prev;
        prev = curr;
    }
    std::cout << ret << std::endl;
    return 0;
}