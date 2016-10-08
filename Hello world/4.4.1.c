#include <stdio.h>
#define BEEP '\n'
#define OOPS "Now you have done it! "
int main(void)
{
    printf("First");
    printf("%c", BEEP);
    printf("%s",OOPS);
    return 0;
}