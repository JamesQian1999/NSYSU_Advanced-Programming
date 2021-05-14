#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

class c
{
public:
    int city, weight;
    c(int c, int w)
    {
        city = c;
        weight = w;
    };
};

int main()
{
    while (1)
    {
        int city;
        cin >> city;
        if (!city)
            break;

        vector<int> hotel;
        vector<c> cities[city + 1];
        string tolken = "";
        int num;

        cin.get();
        hotel.push_back(1);
        hotel.push_back(city);
        //cout << hotel[0] << " " << hotel[1] << " ";
        while (1)
        {
            char tmp = cin.get();
            tolken += tmp;
            if (tmp == ' ')
            {
                hotel.push_back(atoi(tolken.c_str()));
                //cout << hotel[hotel.size() - 1] << " ";
                tolken = "";
            }
            if (tmp == '\n')
                break;
        }
        //cout << endl << endl;
        cin >> num;
        for (int i = 1; i <= num; i++)
        {
            int a, b, weight;
            cin >> a >> b >> weight;
            cities[a].push_back(c(b, weight));
            cities[b].push_back(c(a, weight));
        }
        vector<int> hotel2hotel[city + 1];
        for (int i = 0; i < hotel.size(); i++)
        //for (int i = 0; i < 1; i++)
        {
            cout<<endl;
            int bellmen[city + 1];
            for (int j = 1; j <= city; j++)
                bellmen[j] = 601;
            bellmen[hotel[i]] = 0;
            for (int j = 1; j <= city; j++)
                    cout<<bellmen[j]<<"\t";
            cout<<endl;
            for (int j = 1; j <= city; j++)
            {
                for (int k = 1; k <= city; k++)
                {
                    for (int m = 0; m < cities[k].size(); m++)
                    {
    
                        if (bellmen[k] > bellmen[cities[k][m].city] + cities[k][m].weight)
                        {
                            bellmen[k] = bellmen[cities[k][m].city] + cities[k][m].weight;
                        }
                    }
                    cout<<bellmen[k]<<"\t";
                }
                cout<<endl;
            }
            for (int j = 1; j < hotel.size(); j++)
            {
                if (bellmen[hotel[j]] <= 600)
                    hotel2hotel[hotel[i]].push_back(hotel[j]);
            }
        }
    }
}
/*
6
3 2 5 3
8
1 2 400
3 2 80
3 4 301
4 5 290
5 6 139
1 3 375
2 5 462
4 6 300

*/