#include<iostream>
using namespace std;
int main()
{
    while(1)
    {
        int n, l = 0, r = 1, count = 0;
        cin >> n;
        if(!n) break;
        l = n;
        while(1)
        {
            count++;
            if(count%2) cout<<"Alice:\t";
            else cout<<"Bob:\t";
            cout<<"( "<<r<<" , "<<l<<" )"<<endl;
            if(l > r)
            {
                r = l/2;
                l = l - l/2;
                if(l == 3 && r!=1)
                {
                    l += 1;
                    r -= 1;
                }
            }
            else
            {
                l = r/2;
                r = r - r/2;
                if(r == 3 && l!=1)
                {
                    r += 1;
                    l -= 1;
                }
            }
            if(!r || !l) break;
        }
        if(count%2)
            cout<<"Bob"<<endl;
        else
            cout<<"Alice"<<endl;
        cout<<endl;
    }
}