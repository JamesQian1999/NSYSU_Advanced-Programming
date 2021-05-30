#include <iostream>
using namespace std;

long int dp[26 + 1][26 + 1][(1 + 26) * 26 / 2 + 1];

void caculate()
{
    for (int i = 0; i <= 26; i++)
        for (int j = 0; j <= 26; j++)
            for (int k = 0; k <= 351; k++)
                if (i == k && j == 1)
                    dp[i][j][k] = 1;
                else
                    dp[i][j][k] = 0;

    for (int i = 1; i <= 26; i++)
        for (int j = 1; j <= i; j++)
            for (int k = 1; k <= (1 + 26) * 26 / 2; k++)
            {
                dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j][k]);
                if (k >= i)
                    dp[i][j][k] += dp[i - 1][j - 1][k - i];
            }
}

int main()
{
    caculate();
    int count = 0;
    while (1)
    {
        int l, s;
        cin >> l >> s;
        if (!l && !s)
            break;
        if (l > 26 || s > (1 + 26) * 26 / 2)
            cout << "Case " << ++count << ": 0" << endl;
        else
            cout << "Case " << ++count << ": " << dp[26][l][s] << endl;
    }
}