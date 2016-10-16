#include <stdio.h>
int main(void)
{
    long long n;
    double sum;
    while (~scanf("%lld", &n))
    {
        for (sum = 1; n > 0; n--)
            sum *= n;
        printf("%.lf\n", sum + 11);
    }
    return 0;
}