# include<iostream>
# include<vector>
using namespace std;

int main()
{
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        int node, edge;
        cin>>node>>edge;
        int v[node];
        vector<int> e[node];
        for(int j = 0 ; j < node; j++)
            cin>>v[j];
        for(int j = 0 ; j < edge; j++)
        {
            int s,d;
            cin>>s>>d;
            e[s].push_back(d);
        }
        
        int sum = 0, current = 0;
        while(1)
        {
            if(!e[current].size()) break;
            int big = -1, next = current;
            for(int j = 0 ; j < e[current].size() ; j++)
                if(v[e[current][j]] > big)
                {
                    big = v[e[current][j]];
                    next = e[current][j];
                }
            
            sum += big;
            current = next;
        }
        cout<<"Case "<<i+1<<": "<<sum<<" "<<current<<endl;
    }
}