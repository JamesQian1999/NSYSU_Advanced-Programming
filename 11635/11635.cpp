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
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            int tmp;
            cin >> tmp;
            hotel.push_back(tmp);
        }

        cin >> num;
        for (int i = 1; i <= num; i++)
        {
            int a, b, weight;
            cin >> a >> b >> weight;
            cities[a].push_back(c(b, weight));
            cities[b].push_back(c(a, weight));
        }

        int hotel2hotel[hotel.size()][hotel.size()], count[hotel.size()][hotel.size()], ans[hotel.size()][hotel.size()];
        for (int i = 0; i < hotel.size(); i++)
        {
            int bellmen[city + 1];
            for (int j = 1; j <= city; j++)
                bellmen[j] = 601;
            bellmen[hotel[i]] = 0;

            for (int j = 1; j <= city; j++)
                for (int k = 1; k <= city; k++)
                    for (int m = 0; m < cities[k].size(); m++)
                        if (bellmen[k] > bellmen[cities[k][m].city] + cities[k][m].weight)
                            bellmen[k] = bellmen[cities[k][m].city] + cities[k][m].weight;

            for (int j = 0; j < hotel.size(); j++)
            {
                hotel2hotel[i][j] = 0;
                count[i][j] = 0;
                ans[i][j] = 0;
                if (bellmen[hotel[j]] <= 600)
                {
                    hotel2hotel[i][j] = 1;
                    hotel2hotel[j][i] = 1;
                    count[i][j] = 1;
                    count[j][i] = 1;
                    ans[i][j] = 1;
                    ans[j][i] = 1;
                }
            }
        }

        for (int i = 0; i < hotel.size(); i++)
        {
            for (int j = 0; j < hotel.size(); j++)
                cout << hotel2hotel[i][j] << " ";
            cout << endl;
        }


        int c = 1;
        if (ans[0][1])
        {
            cout << c << endl;
            continue;
        }
        for (int time = 0; time < hotel.size(); time++)
        {
            c++;
            for (int j = 0; j < hotel.size(); j++)
            {
                for (int k = 0; k < hotel.size(); k++)
                {
                    for (int m = 0; m < hotel.size(); m++)
                        ans[j][k] += hotel2hotel[k][m] * count[m][k];
                }
            }
            if (ans[0][1])
                break;
            for (int j = 0; j < hotel.size(); j++)
                for (int k = 0; k < hotel.size(); k++)
                    count[j][k] = ans[j][k];
        }
        if (ans[0][1])
        cout << c << endl;
        else
            cout<<"-1"<<endl;
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
0 

  |  1   6   2   5   3
-----------------------
1 |  1   0   1   0   1
6 |      1   0   1   0
2 |          1   1   1
5 |              1   1
3 |                  1

*/