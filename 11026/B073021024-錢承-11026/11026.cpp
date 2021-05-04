#include<iostream>
#include <cstring>
using namespace std;
int main()
{
	while(1)
    {
        long long N, M,max = -1;
        cin>>N>>M;
        if(N==0 && M==0) break;
        int input[N+1];
        long long dp[N+1][N+1];
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=N; cin>>input[i++]);
        for(int i = 0; i <= N ; i++)
        {
            dp[i][0] = 1;
            for(int j = 1; j <= i; j++)
            {
                dp[i][j] = dp[i-1][j-1]*input[i] + dp[i-1][j];
                dp[i][j] %= M;
            }
        }

        for(int i = 1; i <=N ; i++)
            if(max < dp[N][i]) max = dp[N][i];
        cout<<max<<endl;
    }
}