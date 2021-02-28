#include <iostream>
#include <cmath>
using namespace std;

int prim(long int p)
{
    long int end = (long int)sqrt(p), i;
    if (!end)
        return 0;
    for (i = 2; i <= end; i++)
        if (p % i == 0)
            return 0;
    return 1;
}

int main()
{
    while (1)
    {
        long int input, up, down;
        cin >> input;
        if (!input)
            return 0;
        else if (prim(input))
            cout << "0" << endl;
        else
        {
            for (int i = input;; i++)
                if (prim(i))
                {
                    up = i;
                    break;
                }
            for (int i = input;; i--)
                if (prim(i))
                {
                    down = i;
                    break;
                }
            cout << up - down << endl;
        }
    }
}