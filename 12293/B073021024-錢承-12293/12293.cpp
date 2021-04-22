#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    while(1)
    {
        int n;
        cin >> n;
        if(!n) break;
        long double ans = log2(n+1);
        if(ans==(int)ans)
            cout<<"Bob"<<endl;
        else
            cout<<"Alice"<<endl;
    }
}