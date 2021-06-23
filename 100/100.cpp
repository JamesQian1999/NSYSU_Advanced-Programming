#include <cstdio>
#include <algorithm>
using namespace std;

int cul(int n, int count = 0)
{
    while (n != 1)
    {
        n % 2 ? n = 3 *n + 1 : n = n / 2;
        count++;
    }
    return count + 1;
}

int main()
{
    int a, b, i, max, tmp;
    while (~scanf("%d %d", &a, &b))
        for (i = std::min(a, b), max = -1, tmp = cul(i); i <= std::max(a, b); tmp = cul(++i), i > std::max(a, b) ? printf("%d %d %d\n", a, b, max) : true)
            tmp > max ? max = tmp : true;
}