#include <stdio.h>
void deal(void);
int main(void)
{
    deal();
    return 0;
}

void deal(void)
{
    char ch;
    ch = getchar();
    if (ch != '\n')
    {
        deal();
        printf("%c", ch);
    }
}