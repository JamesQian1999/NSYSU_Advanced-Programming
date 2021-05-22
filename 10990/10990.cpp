#include <iostream>
#include <string.h>
using namespace std;
long int phi[2000001], depth[2000001];

void phi_func()
{
    for (int i = 0; i < 2000001; i++)
        phi[i] = i;

    for (int i = 2; i < 2000001; i++)
        if (phi[i] == i)
            for (int j = i; j < 2000001; j += i)
                phi[j] = phi[j] / i * (i - 1);
}

void depth_func()
{
    memset(depth, 0, 2000001);
    for (int i = 2; i < 2000001; i++)
    {
        long int d = 0;
        int tmp = i;
        while (1)
        {
            d++;
            if (phi[tmp] == 1)
                break;
            tmp = phi[tmp];
        }
        depth[i] = d;
    }
}

int main()
{
    phi_func();
    depth_func();

    int num, m, n;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        long long int sum = 0;
        cin >> m >> n;
        for (int j = m; j <= n; j++)
            sum += depth[j];
        cout << sum << endl;
    }
}