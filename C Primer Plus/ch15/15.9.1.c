#include <stdio.h>
#include <string.h>
int btoi(char * pbin, int bit);

int main(void)
{
    char * pbin = "01001001";
    puts(pbin);
    printf("%d", btoi(pbin, 8));
    return 0;
}

int btoi(char * pbin, int bit)
{
    pbin += bit - 1;
    int ct ,er;
    int to = 0;
    for (ct = 0,er = 1; ct < bit; ct++, er *= 2, pbin--)
        {
            puts(pbin);
            to += (*pbin) * er;
        }
    return to;
}