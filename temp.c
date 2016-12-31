#include <stdio.h>
#include <string.h>
int main(void)
{
    int k = -5;
    if (k < 0)
     k = -k;
    printf("%d", k);
    return 0;
}