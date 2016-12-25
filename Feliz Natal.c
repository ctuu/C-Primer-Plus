//Feliz Natal.c
#include <stdio.h>
#define NUM 40
int main(void)
{
    int ct, temp;
    int num = 2;
    for (temp = NUM - 5; temp; temp--)
        printf(" ");
    printf("Feliz Natal\n");
    for (ct = 0; num < NUM; num <<= 1, ct = (num >> 1) - 1)
    {
        for (; ct <= num; ct++)
        {
            for (temp = NUM - ct; temp; temp--)
                printf(" ");
            if (ct)
                printf("0");
            for (temp = (ct << 1) - 1; temp > 0; temp--)
                printf("1");
            puts("0");
        }
    }
    for (ct = 0; ct < NUM >> 2; ct++)
    {
        for (temp = NUM - NUM / 8; temp--;)
            printf(" ");
        for (temp = NUM / 4 + 1; temp--;)
            printf("0");
        printf("\n");
    }
    return 0;
}