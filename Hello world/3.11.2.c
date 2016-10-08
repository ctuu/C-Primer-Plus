#include <stdio.h>
int main(void)
{
    int num;
    printf("Please enter a number.\n");
    scanf("%d", &num);
    printf("The character for %d is %c", num, num);
    return 0;
}