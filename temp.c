#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char asd;
    asd = 'a';
    int c;
    long long num[91];
    for (num[0] = 0, num[1] = 1, num[2] = 2, c = 3; c < 91; c++)
        num[c] = num[c - 1] + num[c - 2];

    for (c = 0; c < 91; c++)
        printf("%Ld\n", num[c]);
    printf("%c", asd);
    return 0;
}