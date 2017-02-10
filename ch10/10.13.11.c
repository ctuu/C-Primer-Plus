#include <stdio.h>
#define ROW 3
#define COL 5
void dou(int ar[][COL], int n);
void pri(int ar[][COL], int n);
int main(void)
{
    int num[ROW][COL] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15}};
    printf("Origin:\n");
    pri(num, ROW);
    dou(num, ROW);
    printf("\nAfter:\n");
    pri(num, ROW);
    return 0;
}

void dou(int ar[][COL], int n)
{
    int a = n * COL;
    for (; a > -1; a--)
        ar[0][a] *= 2;
}

void pri(int ar[][COL], int n)
{
    int a, b;
    for (a = 0; a < n; a++)
    {
        for (b = 0; b < n; b++)
            printf("%d ", ar[a][b]);
    }
}