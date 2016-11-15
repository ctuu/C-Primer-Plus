#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char *ch;
    ch = (char *)malloc(3 * sizeof(char));
    ch[0] = 'q';
    ch[1] = 'w';
    ch[2] = 'e';
    printf("%s", ch);
    free(ch);
    return 0;
}