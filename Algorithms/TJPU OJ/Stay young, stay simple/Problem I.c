#include <stdio.h>
int main(void)
{
    int T;
    int X, k, t;
    int temp, tec;
    int sum = 0;
    for (scanf("%d", &T); T > 0; T--)
    {
        sum = 0;
        scanf("%d%d%d", &X, &k, &t);
        while (X > 1)
        {
            if (X / k <= X - t)
            {
                temp = X % k;
                while (temp > 0)
                {
                    temp -= t;
                    sum++;
                }
                X = (X - X % k) / k;
                sum++;
            }
            else
            {
                X -= t;
                sum++;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}