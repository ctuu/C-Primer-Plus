#include <stdio.h>
int main(void)
{
    float weight;
    float value;
    printf("Are you worth your weight in paltinum?\n");
    printf("Let's check it out.\n");
    printf("Please enter your weightin pounds: ");
    scanf("%f", &weight);
    value = 1700.0 * weight * 14.5833;
    printf("Your weight in platinum is worth $%.2f. \n", value);
    printf("You are easily worth that! If platinum price drop, \n");
    printf("eat more to maintain youe value. \n");
    return 0;
}
