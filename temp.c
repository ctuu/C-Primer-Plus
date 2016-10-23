#include <stdio.h>
int main(void)
{
    char a[3] = {1, 8, 3};
    char b[3];
    b[1] = a[0] + a[1];
    printf("%d", b[1]);
    return 0;
}