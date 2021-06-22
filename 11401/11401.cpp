#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    long long int dp[1000001], n;
    memset(dp, 0, 1000001);
    for (long long int i = 4; i < 1000001; i++)
        dp[i] = dp[i - 1] + ((i - 1) * (i - 2) / 2 - (i - 1) / 2) / 2;
    while (1)
    {
        cin >> n;
        if (n < 3)
            break;
        cout << dp[n] << endl;
    }
}