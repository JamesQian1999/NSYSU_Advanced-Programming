#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1000001

bool prim[MAX];
void cal()
{
    memset(prim, 1, MAX);
    prim[0] = 0;
    prim[1] = 0;
    for (int i = 2; i < MAX; i++)
        if (prim[i])
            for (int j = i + i; j < MAX; j += i)
                prim[j] = 0;
}

long long unsigned al(long long unsigned n)
{
    long long unsigned ans = 0;
    for (long long unsigned i = 0; i < MAX; i++)
    {
        if (prim[i])
        {
            long long unsigned tmp = i * i;
            if (tmp > n)
                break;
            while (tmp <= n)
            {
                tmp *= i;
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    cal();
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        long long unsigned l, h;
        cin >> l >> h;
        cout << al(h) - al(l - 1) << endl;
    }
}