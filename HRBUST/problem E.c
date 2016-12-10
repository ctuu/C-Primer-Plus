#include <stdio.h>

int main(void)
{
    int T, n, m;
    unsigned long long a[100000];
    unsigned long long b, k, rema, c;
    unsigned long long te, tu;
    for (scanf("%d", &T); T > 0; T--)
    {
        scanf("%d", &n);
        for (te = 0; te < n; te++)
            scanf("%lld", &a[te]);
        scanf("%d", &m);
        for (te = 0; te < m; te++)
        {
            scanf("%lld", &b);
            for (tu = 0; tu < n; tu++)
            {
                if (b == a[tu])
                {
                    b = 0;
                    break;
                }
                if (b < a[tu])
                    continue;
                if (!(a[tu] & a[tu] - 1))
                {
                    b &= (a[tu] - 1);
                    continue;
                }
                rema = 2;
                while (b > a[tu])
                {
                    for (k = 0, c = a[tu]; b >= c; c <<= 1)
                    {
                        if (b - c < a[tu])
                        {
                            rema = b - c;
                            k = 1;
                            break;
                        }
                    }
                    if (b - c < a[tu] && k == 1)
                        break;
                    b -= c >> 1;
                }
                if (b == a[tu])
                    rema = 0;
                else if (b < a[tu])
                    rema = b;
                b = rema;
            }

            printf("%lld\n", b);
        }
    }
    return 0;
}