#include <stdio.h>
void critic(int * ptd);
int main(void)
{
    int units;
    int * ptd = &units;
    printf("How many pounds to a firkin of butter?\n");
    scanf("%d", &units);
    while (units != 56)
        critic(ptd);
    printf("You must have looked it up!\n");

    return 0;
}

void critic(int * ptd)
{
    printf("No luck, my friend. Try again.\n");
    scanf("%d", ptd);
}