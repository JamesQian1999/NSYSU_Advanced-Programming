#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
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
class Hotel2Hotel
{
public:
    char color;
    vector<int> city;
    int path = 0;
    void set(char co, int ci, int p)
    {
        color = co;
        city.push_back(ci);
        path = p;
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

        Hotel2Hotel hotel2hotel[hotel.size()];
        for (int i = 0; i < hotel.size(); i++)
        {
            int bellmen[city + 1];
            for (int j = 1; j <= city; j++)
                bellmen[j] = 601;
            bellmen[hotel[i]] = 0;

            for (int j = 1; j <= city; j++)
            {
                int b = 1;
                for (int k = 1; k <= city; k++)
                    for (int m = 0; m < cities[k].size(); m++)
                        if (bellmen[k] > bellmen[cities[k][m].city] + cities[k][m].weight)
                        {
                            bellmen[k] = bellmen[cities[k][m].city] + cities[k][m].weight;
                            b = 0;
                        }
                if(b) break;
            }

            for (int j = 0; j < hotel.size(); j++)
                if (bellmen[hotel[j]] <= 600 && bellmen[hotel[j]] != 0)
                    hotel2hotel[i].set('w', j, 0);
        }

        queue<Hotel2Hotel> bfs;
        bfs.push(hotel2hotel[0]);
        hotel2hotel[0].color = 'g';
        while (!bfs.empty())
        {
            auto tmp = bfs.front();
            bfs.pop();
            for (int i = 0; i < tmp.city.size(); i++)
            {
                if (hotel2hotel[tmp.city[i]].color == 'w')
                {
                    hotel2hotel[tmp.city[i]].color = 'g';
                    hotel2hotel[tmp.city[i]].path = tmp.path + 1;
                    bfs.push(hotel2hotel[tmp.city[i]]);
                }
            }
            tmp.color = 'b';
        }

        if (hotel2hotel[1].path)
            cout << hotel2hotel[1].path - 1 << endl;
        else
            cout << "-1" << endl;
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

3
0
2
1 2 371
2 3 230


     0   1   2   3   4
  |  1   6   2   5   3
-----------------------
1 |  1   0   1   0   1
6 |      1   0   1   0
2 |          1   1   1
5 |              1   1
3 |                  1

*/