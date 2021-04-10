#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 1001 
int main()
{
    int num, n, i, j, place[MAX][MAX]={0}, ans[MAX]={0};
    
    for(i = 0; i < MAX; i++)
        place[1][i] = 1;
    
    for(i = 2; i < MAX; i++)
        for(j = i; j < MAX; j++)
            place[i][j] = place[i-1][j-1]%10056*i%10056 + place[i][j-1]%10056*i%10056;
    
    for(int i = 1; i<MAX; i++)
        for(int j = 1; j<=i; j++)
            ans[i]=(ans[i]+place[j][i])%10056;


    cin>>num;
    for(i=0; i<num; i++)
    {
        cin>>n;
        cout<<"Case "<<i+1<<": "<<ans[n]<<endl;        
    }
}