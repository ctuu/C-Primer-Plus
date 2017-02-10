#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
int num[MAX];
void quicksort(int i, int j);
int main(void)
{
    int co;
    srand((unsigned int) time(0));
    for (co = 0; co <MAX; co++)
        num[co] = rand() % 10 + 1;
    quicksort(0, MAX - 1);
    for (co = 0; co <MAX; co++)
        printf("%d\n", num[co]);
    return 0;
}

void quicksort(int i, int j)
{
    int a = i;
    int b = j - 1;
    int temp;
    if (a < b)
    {
        for (; a < b;)
        {
            while (num[a] <= num[j] && a < b)
                a++;
            while (num[b] > num[j] && a < b)
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
    else if (a == b)
    {
        if (num[i] > num[j])
        {
            temp = num[i];
            num[i] = num[j];
            num[j] = temp;
        }
    }
}