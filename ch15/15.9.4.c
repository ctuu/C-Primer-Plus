#include <stdio.h>
#define LIMIT 8
int che(int num, int ct);
int main(void)
{
    int num, ct;
    scanf("%d%d", &num, &ct);
    printf("%d", che(num, ct));
    return 0;
}

int che(int num, int ct)
{
    int i, sum;
    for (sum = 0, i = LIMIT; i > 0; i--, num >>= 1)
        if (ct-- == 0 && (01 & num) == 1)
            sum = 1;
    return sum;
}