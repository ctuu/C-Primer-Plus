#include <stdio.h>
#define NUM 2
int main(void)
{
    int a, b, c;
    int n[NUM]= {2, 4};
    for (a = 0; a < NUM;a++)
        for (c = 1000, b = n[a];b > 0; b--, c--)
        {
            printf("%d",b);
        }
}