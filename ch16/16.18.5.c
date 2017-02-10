#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIM 10

void choose(int num[], int n, int m);

int main(void)
{
    int num[LIM] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    choose(num, LIM, 4);
    return 0;
}

void choose(int num[], int n, int m)
{
    int te;
    srand((unsigned int)time(0));
    while (m--)
    {
        te = rand() % n;
        while (num[te] == -1)
            te = rand() % n + 1;
        printf("%d: %d\n", te + 1, num[te]);
        num[te] = -1;
    }
}
