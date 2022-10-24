#include <iostream>

int main()
{
    bool foundtarget = false;
    int x = 20;
    while (!foundtarget)
    {
        for (unsigned i = 11; i <= 20; ++i)
        {
            if (x % i)
                break;
            if (i == 20)
                std::cout << x, foundtarget = true;
        }
        x++;
    }
    return 0;
}