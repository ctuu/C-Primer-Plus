#include <stdio.h>
#define NUM 2
#define MAX 1001
int main(void)
{
    int a, b, c;
    int n[NUM];
    int num[NUM + 1][MAX] = {0};
    for (a = 0; a < NUM; a++)
        for (b = 1; (num[a][b] = getchar()) != '\n' && b < MAX; b++)
            n[a] = b;
    for (a = 0; a < NUM; a++)
        for (c = 0, b = 1; b < MAX; b++)
            if (num[a][b] == 10 || c == 1)
            {
                c = 1;
                continue;
            }
            else
                printf("%d ", num[a][b] - 48);
    
        for (a = 0; a < NUM; a++)
    {
        for (c = 1000, b = n[a]; b <= 1000; b++, c--)
        {
            num[a][c] = num[a][b] - 48;
            num[a][b] = 0;
        }
    }
}