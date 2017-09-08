#include <stdio.h>
int main(void)
{
    char a;
    scanf("%s", &a);
    int n = a - 'A' + 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - i; ++j)
            printf(" ");
        int j = -1;
        while (j++ < i)
            printf("%c", 'A' + j);
        j -= 1;
        while (j-- > 0)
            printf("%c", 'A' + j);
        printf("\n");
    }
    return 0;
}