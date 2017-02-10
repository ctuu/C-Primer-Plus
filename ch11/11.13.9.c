#include <stdio.h>
#include <string.h>
#define MAX 80
int main(void)
{
    int co;
    int n = 0;
    char temp[1];
    char ch[MAX];
    while (fgets(ch, MAX, stdin) != NULL)
    {
        co = strlen(ch) - 2;
        if (ch[co] == '\n')
            ch[co] = '\0';

        for (n = 0; n <= co; n++, co--)
        {
            temp[0] = ch[n];
            ch[n] = ch[co];
            ch[co] = temp[0];
        }
        puts(ch);
    }
    return 0;
}