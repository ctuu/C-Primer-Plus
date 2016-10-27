#include <stdio.h>
int main(void)
{
    char a[20];
    fgets(a, 20, stdin);
    printf("%s\nHello World!", a);
    return 0;
}