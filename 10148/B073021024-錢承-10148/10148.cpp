#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int c;
    cin >> c;
    for (int i = 0; i < c; i++)
    {
        int ad, run;
        cin >> ad >> run;
        int path[run][2]; // 0 for start, 1 for end
        for (int j = 0; j < run; j++)
        {
            int a, b;
            cin >> a >> b;
            if (a < b)
            {
                path[j][0] = a + 10000;
                path[j][1] = b + 10000;
            }
            else
            {
                path[j][0] = b + 10000;
                path[j][1] = a + 10000;
            }
        }

        for (int j = 0; j < run; j++)
        {
            int min = path[j][1], p = j;
            for (int k = j + 1; k < run; k++)
                if (path[k][1] < min)
                    min = path[p = k][1];

            int tmp1 = path[p][0], tmp2 = path[p][1];
            path[p][0] = path[j][0];
            path[p][1] = path[j][1];
            path[j][0] = tmp1;
            path[j][1] = tmp2;
        }

        // cout << endl;
        // for (int j = 0; j < run; j++)
        //     cout << path[j][0] << " " << path[j][1] << endl;
        bool list[20002] = {0};
        int start = 0, end = path[run - 1][1], ad_num = 0;
        for (int j = 0; j < run; j++)
        {
            if (path[j][1] - path[j][0] + 1 < ad)
            {
                for (int k = path[j][0]; k <= path[j][1]; k++)
                {
                    if (!list[k])
                    {
                        list[k] = 1;
                        ad_num++;
                    }
                }
            }
            else
            {
                int count = 0, add = ad;
                for (int k = path[j][0]; k <= path[j][1]; k++)
                    if (list[k])
                        count++;

                if (count >= ad)
                    continue;

                add = add - count;
                for (int k = path[j][1]; add != 0; k--)
                {
                    if (!list[k])
                    {
                        list[k] = 1;
                        ad_num++;
                        add--;
                    }
                }
            }

        }

        cout << ad_num << endl;
        for (int j = 0; j <= end; j++)
            if (list[j])
                cout << j - 10000 << endl;
        if (i != c - 1)
            cout << endl;
    }
}
/*
2

5 4
2 -5
-1 4
10 4
7 13

5 10
1 10
20 27
0 -3
15 15
8 2
7 30
-1 -10
27 20
2 9
14 21
*/

