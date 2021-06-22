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
        int start = 0, end = path[run - 1][1];
        for (int j = 0; j < run; j++)
        {
        }
    }
}