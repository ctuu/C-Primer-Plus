#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int main(void)
{
    int seed;
    int num[MAX];
    int sum[10] = {0};
    int ct;
    printf("Please enter a number as the seed: ");
    while (~scanf("%d", &seed))
    {
        int sum[10] = {0};
        srand(seed);
        for (ct = 0; ct < MAX; ct++)
        {
            num[ct] = rand() % 10 + 1;
            switch (num[ct])
            {
            case 1:
                sum[0] += 1;
                break;
            case 2:
                sum[1] += 2;
                break;
            case 3:
                sum[2] += 1;
                break;
            case 4:
                sum[3] += 1;
                break;
            case 5:
                sum[4] += 1;
                break;
            case 6:
                sum[5] += 1;
                break;
            case 7:
                sum[6] += 1;
                break;
            case 8:
                sum[7] += 1;
                break;
            case 9:
                sum[8] += 1;
                break;
            case 10:
                sum[9] += 1;
                break;
            }
        }
        for (ct = 0; ct < 10; ct++)
            printf("%2d appear %4d times.\n", ct + 1, sum[ct]);
        printf("\nPlease enter a number as the seed: ");
    }
    return 0;
}