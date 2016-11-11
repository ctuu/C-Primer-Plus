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
    //printf("=.=");
    int a = i;
    int b = j - 1;
    int temp;

    if (j > i + 1)
    {
        for (; b > a + 1;)
        {
            for (; num[a] < num[j] && a < b - 1;)
                a++;
            for (; num[b] > num[j] && a < b - 1;)
                b--;
            if (num[a] >= num[j] && num[b] <= num[j])
            {
                temp = num[a];
                num[a] = num[b];
                num[b] = temp;
            }
        }
        if (num[a] > num[j])
        {
        temp = num[a];
        num[a] = num[j];
        num[j] = temp;
        }
        quicksort(i, a);
        quicksort(b, j);
    }
    else if(num[i] > num [j])
    {
        temp = num[i];
        num[i] = num[j];
        num[j] = temp;
    }
}