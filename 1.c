#include <stdio.h>
int aqq(int a, int b);

int main(void)
{
    int s, a, b;
    s = a = b = 0;
    s += aqq(a - 1, b - 1);
}
int aqq(int a, int b)
{
    return 1;
}