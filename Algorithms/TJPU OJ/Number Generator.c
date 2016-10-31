#include <stdio.h>
int co = 0;
void dfs(int n);
int main(void)
{
    int a;
    while (~scanf("%d", &a))
    {
        dfs(a);
        printf("%d\n", co + 1);
        co = 0;
    }
    return 0;
}

void dfs(int n)
{
    int i;
    for (i = 1; i <= n / 2; i++)
    {
        co++;
        dfs(i);
    }
}