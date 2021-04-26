// Created on J’ iPad.

#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
    set<string> list;
    string tocken;
    char c;
    while(cin.get(c))
    {
        if(!((c>=65 && c<=90)||(c>=97 && c<=122)))
        {
            for(int i = 0; i<tocken.size() ; i++)
            {
                if(tocken[i]>=65 && tocken[i]<=90)
                    tocken[i] += 32;
            }
            list.insert(tocken);
            tocken = "";
        }
        else
            tocken+=c;
    }
    for(set<string>::iterator it = list.begin() ;it!=list.end();it++)
        if(it!=list.begin())
            cout<<*it<<endl;
}