#include <stdio.h>
int main(void)
{
    float inch,height;
    printf("Enter your height(/inch):");
    scanf("%f", &inch);
    height = inch * 2.54;
    printf("Your height is %f cm", height);
    return 0;
}