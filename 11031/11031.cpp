#include <iostream>
using namespace std;
int main()
{
    int n,q;
    do
    {
        cin >> n >> q;
        if(!n && !q) break;
        int list[n][2];
        for(int i=0; i<n; i++)
        {
            cin >> list[i][0];
            list[i][1]=-1;
        }
        for(int i=0; i<n; i++)
        {
            int count = 0 , find = list[i][0];
            for(int j=0; j<n; j++)
            {   
                //if(list[j][1]!=-1) continue;
                if(find <= list[j][0])
                {
                    if(list[j][1]==-1 || list[j][1]>count+1)
                        list[j][1] = ++count;
                
                    find = list[j][0];
                }   
            }
        }
        cout<<endl;
        for(int i=0 ; i<n ; i++)
            cout<<list[i][0]<<" ";
        cout<<endl;
        for(int i=0 ; i<n ; i++)
            cout<<list[i][1]<<" ";
        cout<<endl;
    } while (1);
    
}