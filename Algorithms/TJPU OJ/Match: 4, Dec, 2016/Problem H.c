#include <stdio.h>
#include <string.h>
int main(void)
{
    int su, max;
    int T, t, ct, cts, str;
    int tag;
    char ch[100000];
    scanf("%d", &T);
    for (t = 0; t < T; t++)
    {
        scanf("%s", ch);
        str = strlen(ch);
        printf("Case #%d: ", t + 1);
            max = (max > su) ? max : su;
        }
        printf("%d\n", max);
    }
    return 0;
}