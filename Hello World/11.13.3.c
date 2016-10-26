#include <stdio.h>
#define MAX 80
void input(char *ch);

int main(void)
{
    char ch[MAX];
    input(ch);
    puts(ch);

    return 0;
}

void input(char *ch)
{
    scanf("%s", ch);
}