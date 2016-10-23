#include <stdio.h>
#define NUM 2
int main(void)
{
    int a, b, c, d;
    int n[NUM];
    char num[NUM + 1][1001] = {0};
    for (a = 0; a < NUM; a++)
        for (b = 1; (num[a][b] = getchar()) != '\n'; b++)
            n[a] = b;

    for (a = 0; a < NUM; a++)
    {
        for (c = 1000, b = n[a]; b <= 1000; b++, c--)
        {
            num[a][c] = num[a][b];
            num[a][b] = 0;
        }
    }

    for (a = 0; a < NUM; a++)
    {
        for (d = 0, c -= 1; c < 1001; c++)
        {
            num[2][c] = num[2][c] + num[a][c];
            if (num[a][c] != 10 && d == 0)
                printf("%c %c\n",num[2][c], num[a][c]);
            else
                d = 1;
                continue;
        }
    }
    for ( b = 1; b < 1000; b++)
       // printf("%c ", num[2][b]);
    return 0;
}