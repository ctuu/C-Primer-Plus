#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char ch;
    ch = getchar();
    if (ch == '-')
        printf("!!");
    else
        printf("@@");
    return 0;
}