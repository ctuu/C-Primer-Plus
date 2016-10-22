#include <stdio.h>
int main(void)
{
    float quart;
    float num;
    printf("Enter the quart of water:");
    scanf("%f",&quart);
    num = 950/(3.0e-23);
    printf("\n The number of %f quart water is %e", quart, num);
    return 0;
}