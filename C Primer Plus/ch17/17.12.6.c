#include <stdio.h>
#define MAX 10
int sear(int num[], int temp);
int main(void)
{
    int temp;
    int num[MAX] = {1, 3, 5, 12, 23, 45, 48, 52, 56, 60};
    scanf("%d", &temp);
    printf("%d", sear(num, temp));

    return 0;
}

int sear(int num[], int temp)
{
    int loc = MAX / 2;
}