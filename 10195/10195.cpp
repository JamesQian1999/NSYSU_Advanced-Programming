#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    long double a,b,c,s,area,r;
    while(cin>>a>>b>>c)
    {
        if(a==0 || b==0 || c==0)
        {
            printf("The radius of the round table is: 0.000\n");
            continue;
        }
        s = (a+b+c)/2;
        area = sqrt(s*(s-a)*(s-b)*(s-c));
        r = area/s;
        printf("The radius of the round table is: %.3llf\n",r);
    }
}