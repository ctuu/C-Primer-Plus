#include <stdio.h>
int main(void)
{
    char ch;
    ch = getchar();
    printf("%c %d", ch - 32, ch - 32);
    return 0;
}