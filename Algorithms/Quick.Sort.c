#include <stdio.h>
#define NUM 9
int num[NUM] = {3, 7, 5, 4, 2, 6, 8, 1, 2};
void quicksort(int i, int j);

int main(void)
{
    int a = NUM;
    int b;
    for (b = 0; b < a; b++)
        printf("%d ", num[b]);
    printf("\n");
    printf("=0=\n");
    quicksort(0, NUM - 1);
    for (b = 0; b < a; b++)
        printf("%d ", num[b]);
    return 0;
}

void quicksort(int i, int j)
{
    int a, b, temp;
    for ( i < j)
    {
        for (a = i, b = j - 1; b > a;)
        {
            for (;num[a] < num[j] && a < b;)
                a++;
        }
    }
}