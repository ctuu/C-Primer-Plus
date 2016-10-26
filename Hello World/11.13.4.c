#include <stdio.h>
#define MAX 80
void input(char *ch, int n);

int main(void)
{
    char ch[MAX];
    input(ch, 10);
    puts(ch);

    return 0;
}

void input(char *ch, int n)
{
    int a;
    for (a = 0; a < n; a++)
        {
            scanf("%1s", ch);
            ch++;
        }
}