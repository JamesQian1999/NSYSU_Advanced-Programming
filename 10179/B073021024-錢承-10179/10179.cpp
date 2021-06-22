#include <iostream>
#include <cstring>
using namespace std;

#define MAX 500000
long long phi[MAX], fac[30];
bool prim[MAX];

void prime()
{
    memset(prim, 1, MAX);
    prim[0] = 0;
    prim[1] = 0;
    for (int i = 2; i < MAX; i++)
        if (prim[i])
            for (int j = i + i; j < MAX; j += i)
                prim[j] = 0;
}

void phi_func()
{
    for (int i = 0; i < MAX; i++)
        phi[i] = i;

    for (int i = 2; i < MAX; i++)
        if (phi[i] == i)
            for (int j = i; j < MAX; j += i)
                phi[j] = phi[j] / i * (i - 1);
}

long long cal(long long num)
{
    int count = 0, base = 0;
    long long ans = num;
    for (int i = 2; i < MAX; i++)
    {
        if (prim[i])
            if (!(num % i))
            {
                fac[count++] = i;
                while (!(num % i))
                    num /= i;
            }
    }

    if (num > 1)
        fac[count++] = num;

    for (int i = 0; i < count; i++)
        ans = ans / fac[i] * (fac[i] - 1);

    return ans;
}

int main()
{
    phi_func();
    prime();
    while (1)
    {
        long long num;
        cin >> num;
        if (!num)
            break;
        if (num < MAX)
            cout << phi[num] << endl;
        else
            cout << cal(num) << endl;
    }
}