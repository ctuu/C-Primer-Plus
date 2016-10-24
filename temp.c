#include <stdio.h>
#define NUM 2
#define MAX 1002
int main(void)
{
    int a, b, c, count, t, s;
    int n[NUM];
    scanf("%d", &count);
    while (getchar() != '\n')
        continue;
    for (t = 1; t <= count; t++)
    {
        printf("Case %d:\n", t);

        int num[NUM + 1][MAX] = {0};

        for (a = 0; a < NUM; a++)
            for (b = 1; (num[a][b] = getchar()) != '\n' && b < MAX; b++)
                n[a] = b;

        for (a = 0; a < NUM; a++)
            for (c = MAX - 1, b = n[a] + 1; b > 0; b--, c--)
            {
                if (num[a][b] == 10)
                {
                    num[a][b] = 48;
                    c = MAX;
                }
                num[a][c] = num[a][b] - 48;
                num[a][b] = 0;
            }

        for (a = 0; a < NUM; a++)
            for (b = 1; b < MAX; b++)
                num[NUM][b] += num[a][b];

        for (b = MAX - 1; b > 0; b--)
            while (num[NUM][b] >= 10)
            {
                num[NUM][b] -= 10;
                num[NUM][b - 1] += 1;
            }

        for (a = 0; a < NUM; a++)
        {
            for (c = 0, b = 0; b < MAX; b++)
            {
                if (num[a][b] == 0 && c == 0)
                {
                    if (b == MAX - 1 && c == 0)
                        for (s = 0; s < n[a]; s++)
                            printf("%d", num[a][b]);
                    continue;
                }
                else
                {
                    c = 1;
                    printf("%d", num[a][b]);
                }
            }
            if (a < NUM - 1)
                printf(" + ");
        }

        printf(" = ");
        for (c = 0, b = 0; b < MAX; b++)
        {
            if (num[NUM][b] == 0 && c == 0)
            {
                if (b == MAX - 1 && c == 0)
                    printf("%d", num[NUM][b]);
                continue;
            }
            else
            {
                c = 1;
                printf("%d", num[NUM][b]);
            }
        }

        if (t != count)
            printf("\n\n");
        else
            printf("\n");
    }
    return 0;
}