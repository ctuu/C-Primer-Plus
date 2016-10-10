#include <stdio.h>
int main(void)
{
    int word[15][15];
    int num, count;
    int a, b;
    scanf("%d", &num);
    while (getchar != '\n')
    {
        for (a = 0; a < num; a++)
            for (b = 0; getchar() != ' '; b++)
                word[a][b] = getchar();
    }
    for (a = 0; a < num; a++)
        for (b = 0; b < 15; b++)
            putchar(word[a][b]);

    return 0;
}