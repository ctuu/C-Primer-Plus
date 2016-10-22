#include <stdio.h>
int main(void)
{
    char ch;
    printf("PLease enter a character.\n");
    scanf("%c", &ch);
    printf("The code foc %c is %d.\n", ch, ch);
    return 0;
}