#include <stdio.h>
#define N 10
void input(char * ch, int n);
int main(void)
{
    char ch[N] = {'\0'};
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
}