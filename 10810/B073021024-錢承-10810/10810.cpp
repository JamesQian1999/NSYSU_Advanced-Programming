#include <iostream>
using namespace std;

long long int count;

void merge(int *list, int l, int r, int rlast)
{
    int tmp[rlast-l+1]={0},llast = r-1 ,lptr = l , rptr = r, current = 0;
    while(1)
    {
        if(lptr == llast+1 && rptr == rlast+1) break;
        else if (lptr == llast+1)
        {
            for(; rptr <= rlast; rptr++)
                tmp[current++] = list[rptr];
            break;
        }
        else if (rptr == rlast+1)
        {
            for(; lptr <= llast; lptr++)
                tmp[current++] = list[lptr];
            break;
        }
        else
        {
            if(list[lptr]>list[rptr])
            {
                tmp[current++] = list[rptr++];
                count += (llast-lptr+1);
            }
            else
                tmp[current++] = list[lptr++];
        }
    }
    for(int i = 0, j = l; j <= rlast ; j++)
        list[j] = tmp[i++];
}

void mysort(int *list, int s, int e)
{
    if (s==e) return;
    int mid = (e+s)/2;
    mysort(list,s,mid);
    mysort(list,mid+1,e);
    merge(list,s,mid+1,e);
}

int main() {
    while(1)
    {
        count = 0;
        int num;
        cin>> num;
        if(!num) break;
        int list[num];
        for(int i=0 ; i<num ; i++)
            cin>>list[i];
        mysort(list,0,num-1);
        cout<<count<<endl;
    }
}