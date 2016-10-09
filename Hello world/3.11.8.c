#include <stdio.h>
int main(void)
{
    float pint,bottle;
    int oz,tspoon,spoon;
    printf("Enter the number of bottle:");
    scanf("%f", &bottle);
    pint = bottle / 2;
    oz = bottle * 8 ;
    spoon = oz * 2 ;
    tspoon = spoon *3 ;
    printf("\n %f bottle = %f pint = %d oz = %d spoon = %d tspoon", bottle, pint, oz, spoon, tspoon);
    return 0; 
}