#include <stdio.h>
#include <string.h>
#define MX 80
char *string_in(char *b, char *a);
int main(void)
{
    char oc[MX];
    char sc[MX];
    while (fgets(oc, MX, stdin) != NULL && fgets(sc, MX, stdin) != NULL)
        printf("%p\n", string_in(oc, sc));
    return 0;
}

char *string_in(char *b, char *a)
{
    int n = 0;
    int k = 0;
    int q = strlen(b) - 1;

    for (; *a != '\0'; n++, a++)
    {
        if (k == q)
            return a - q;
        if (*a == *b || *b == '\0')
        {
            k++;
            if (*b != '\0')
                b++;
        }
        else
        {
            b -= k;
            k = 0;
        }
    }

    if (k != q)
        return NULL;
}