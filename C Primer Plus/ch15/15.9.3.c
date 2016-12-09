#include <stdio.h>
#define LIMIT 8
int che(int num);
int main(void)
{
    int num;
    scanf("%d", &num);
    printf("%d", che(num));
    return 0;
}

int che(int num)
{
    int i, sum;
    for (sum = 0, i = LIMIT; i > 0; i--, num >>= 1)
        if ((01 & num) == 1)
            sum++;
    return sum;
}