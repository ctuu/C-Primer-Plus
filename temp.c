#include <stdio.h>
#include <string.h>
int main(void)
{
    char a[10] = "ads";
    char b[10];
    sprintf(b, "%s", a);
    puts(b);
    return 0;
}