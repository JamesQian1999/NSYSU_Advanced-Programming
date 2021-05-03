#include <iostream>
using namespace std;
#define MAX(a,b) a > b ? a : b
int main()
{
    int case_;
    cin>>case_;
    for(int c = 0 ; c < case_ ; c++)
    {   
        int num,max=0;
        cin>>num;
        int car[num],increase[num],decrease[num];
        for(int j = num-1 ; j >=0 ; j--)
        {
            cin>>car[j];
            increase[j] = 1;
            decrease[j] = 1;
        }
        for(int j = 0 ; j < num ; j++)
        {
            for(int k = j+1 ; k < num ; k++)
            {
                if(car[j] > car[k])
                    increase[k] = MAX(increase[j]+1,increase[k]);
                if(car[j] < car[k])
                    decrease[k] = MAX(decrease[j]+1,decrease[k]);
            }
        }
        for(int j = 0 ; j < num ; j++)
            if(max < increase[j]+ decrease[j]-1)
                max = increase[j] + decrease[j]-1;
            cout<<max<<endl;
    }
}