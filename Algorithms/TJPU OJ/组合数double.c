#include <stdio.h>
int main(void)
{
    int n, m;
    double c, d;
    while (~scanf("%d%d", &n, &m))
    {
        for (c = 1, d = m; d >= m - n + 1; d--)
            c *= d;
        for (d = n; d > 1; d--)
            c /= d;
        printf("%.lf\n", c);
    }
    return 0;
}