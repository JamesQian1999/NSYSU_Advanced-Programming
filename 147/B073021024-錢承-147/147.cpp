
#include <stdio.h>
#include <string.h>
using namespace std;

#define MAX 30001
void cul();
long long int dp[MAX][12];
int m[11] = {2000, 1000, 400, 200, 100, 40, 20, 10, 4, 2, 1};

int main()
{
    cul();
    double input;
    while (1)
    {
        scanf("%lf", &input);
        if (input == 0.00)  break;
        int converted = (int)(input * 20 + 0.5);
        printf("%6.2f%17lld\n", input, dp[converted][0]);
    }
}

void cul()
{
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < 11; i++)
        dp[0][i] = 1;

    for (int i = 1; i < MAX; i++)
        for (int j = 11; j >= 0; j--)
        {
            dp[i][j] = dp[i][j + 1];
            if (i >= m[j])
                dp[i][j] += dp[i - m[j]][j];
        }
}
