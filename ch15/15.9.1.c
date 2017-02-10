#include <stdio.h>
#include <string.h>
int btoi(char *pbin, int bit);

int main(void)
{
    char *pbin = "01001001";
    printf("%d", btoi(pbin, 8));
    return 0;
}

int btoi(char *pbin, int bit)
{
    int er;
    int to = 0;
    for (er = 1; bit > 0; er *= 2, bit--)
        to += (pbin[bit - 1] - 48) * er;
    return to;
}