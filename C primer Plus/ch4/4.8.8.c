#include <stdio.h>
#define GALTOL 3.785
#define MITOKM 1.609
int main(void)
{
    float mileage,gas;
    printf("Enter your trip's mileage:\n");
    scanf("%f",&mileage);
    printf("Enter gas which have used:\n");
    scanf("%f",&gas);
    printf("per gal can drive %.1f mi.\n", mileage / gas);
    printf("drive per km need %.1f l gas.", (gas * GALTOL) / (mileage * MITOKM));
    return 0;
}