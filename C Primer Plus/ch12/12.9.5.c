#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
int main(void)
{
    int nums[MAX];
    int co;
    srand((unsigned int) time(0));
    for (co = 0; co <  MAX; co++)
        nums[co] = rand() % 10 + 1;
    for (co = 0; co < MAX; co++)
        printf("%d: %d\n", co + 1, nums[co]);
    return 0;
}