#include <stdio.h>
#define MAX 80
void deal(char *ch);
int main(void)
{
    char ch[MAX];
    while (fgets(ch, MAX, stdin) != NULL && ch[0] != '\n')
    {
        deal(ch);
        puts(ch);
    }
    puts("Done.");
    return 0;
}

void deal(char *ch)
{
    int co, ca;
    for (co = ca = 0; ch[co] != '\n'; co++)
    {
        if (ch[co] == ' ')
            continue;
        else
        {
            ch[ca] = ch[co];
            ca++;
        }
    }
    ch[ca] = '\0';
}