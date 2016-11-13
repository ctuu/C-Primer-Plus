#include <stdio.h>
int main(void)
{
    int num, k;
    int t = 0;
    int n = 0;
    _Bool oj = 0;
    char dir[200000] = {0};
    int xy[200000] = {0};
    while (~scanf("%d", &num))
    {
        int t = 0;
        int n = 0;
        _Bool oj = 0;
        char dir[200000] = {0};
        int xy[200000] = {0};
        while (getchar() != '\n')
            continue;
        for (k = 0; k < num; k++)
        {
            dir[k] = getchar();
            if (k > 0 && (dir[k - 1] != 'L' && dir[k] == 'L' || dir[k - 1] != 'R' && dir[k] == 'R'))
                oj = 1;
        }
        for (k = 0; k < num; k++)
            scanf("%d", &xy[k]);
        if (oj == 0)
            printf("-1\n");
        else
        {
            while (n != 1)
            {
                for (k = 0; k < num; k++)
                {
                    if (dir[k] == 'R')
                        xy[k] += 1;
                    else if (dir[k] == 'L')
                        xy[k] -= 1;
                }
                t++;
                for (k = 0; k < num - 1; k++)
                    if (xy[k] == xy[k + 1])
                        n = 1;
            }
            printf("%d\n", t);
        }
    }
    return 0;
}
