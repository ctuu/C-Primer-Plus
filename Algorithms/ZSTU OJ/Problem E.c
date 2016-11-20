#include <stdio.h>
#define Y 2017
#define M 10
#define D 28
int main(void)
{
    int y, m, d, ct, sum;
    while (~scanf("%d", &ct))
    {
        for (sum = 0; ct > 0; ct--)
        {
            scanf("%d%d%d", &y, &m, &d);
            if (Y > y)
            {
                sum += (Y - y) * 365;
                if (y <= 2016 && m <= 2)
                    sum += 1;
                if (y < 2016 && m > 2)
                    sum += 1;
                if ((Y - 1 - y) / 4 > 1)
                            sum += (Y - 1 - y) / 4;
            }
            if (m > 11)
                sum -= 31;
            if (m > 10)
                sum -= 30;
            if (m < 10)
                sum += 30;
            if (m < 9)
                sum += 31;
            if (m < 8)
                sum += 31;
            if (m < 7)
                sum += 30;
            if (m < 6)
                sum += 31;
            if (m < 5)
                sum += 30;
            if (m < 4)
                sum += 31;
            if (m < 3)
                sum += 28;
            if (m < 2)
                sum += 31;
            if (D > d)
                sum += (D - d);
            else
                sum -= (d - D);
            printf("%d\n", sum);
            sum = 0;
        }
    }
    return 0;
}
