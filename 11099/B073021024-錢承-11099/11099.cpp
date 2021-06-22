#include <iostream>
#include <set>
#include <cstring>
using namespace std;

#define MAX 1000001
bool prime[MAX];
long int p[78498];

void table()
{
    memset(prime, 1, sizeof(prime));
    int tmp = 0;
    prime[0] = 0;
    prime[1] = 0;
    for (long int i = 2; i < MAX; i++)
        if (prime[i])
        {
            p[tmp++] = i;
            for (long int j = 2 * i; j < MAX; j += i)
                prime[j] = 0;
        }
}

int main()
{
    table();
    long int input;
    while (cin >> input)
    {
        if (input <= 1)
        {
            cout << "Not Exist!" << endl;
            continue;
        }

        long int e[300], tmp = input;
        set<long int> myset;
        int top = 0;
        memset(e, -1, sizeof(e));

        if (prime[input])
        {
            if (input*input > 2000000)
                cout << "Not Exist!" << endl;
            else
                cout << input*input << endl;
            continue;
        }

        for (long int i = 0; i < 78498; i++)
        {
            long int flag = 0;
            while (tmp % p[i] == 0)
            {
                tmp /= p[i];
                flag = 1;
            }
            if (flag)
                e[top++] = p[i];
            if (tmp == 1)
                break;
        }

        long int min = 1, first;
        for (long int i = 0; i < top; i++)
            min *= e[i];
        myset.insert(min);

        while (1)
        {
            first = *myset.begin();
            if (first > input)
            {
                if (first > 2000000)
                    cout << "Not Exist!" << endl;
                else
                    cout << first << endl;
                break;
            }
            if (first > 1000000)
            {
                cout << "Not Exist!" << endl;
                break;
            }
            for (long int i = 0; i < top; i++)
                myset.insert(first * e[i]);

            myset.erase(first);
        }
    }
}