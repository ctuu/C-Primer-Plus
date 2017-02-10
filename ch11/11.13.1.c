#include <stdio.h>
#define N 11
void input(char * ch, int n);
int main(void)
{
    int n;
    char ch[N] = {};
    input (ch, N - 1);
    puts(ch);
    return 0;
}

void input(char * ch, int n)
{
    int a, b;
    for (a = 0; a < n; a++)
    {
        b = getchar();
        if (b != EOF)
            ch[a] = b;
        else
            break;
    }
    ch[a] = '\0';
}