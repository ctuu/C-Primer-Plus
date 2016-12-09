#include <stdio.h>
#include <limits.h>
#define LIMIT 8
char *itobs(int, char *);
int btois(char *pbin, int bit);
void show_bstr(const char *);
int main(void)
{
    char bio[LIMIT];
    char bit[LIMIT];
    char temp[LIMIT + 1];
    int nuo, nut;
    printf("Please enter the first binary number:\n");
    scanf("%s", bio);
    nuo = btois(bio, LIMIT);
    printf("Please enter the second binary number:\n");
    scanf("%s", bit);
    nut = btois(bit, LIMIT);

    //    printf("%d  %d\n", nuo, nut);
    printf("\"~\" bitwise:");
    printf("\n1) ");
    itobs(~nuo, temp);
    show_bstr(temp);
    printf("\n2) ");
    itobs(~nut, temp);
    show_bstr(temp);

    printf("\n\n\"&\" bitwise:\n   ");
    itobs(nuo&nut, temp);
    show_bstr(temp);

    printf("\n\n\"|\" bitwise:\n   ");
    itobs(nuo | nut, temp);
    show_bstr(temp);

    printf("\n\n\"^\" bitwise:\n   ");
    itobs(nuo^nut, temp);
    show_bstr(temp);
    return 0;
}

int btois(char *pbin, int bit)
{
    int er;
    int to = 0;
    for (er = 1; bit > 0; er *= 2, bit--)
        to += (pbin[bit - 1] - 48) * er;
    return to;
}

char *itobs(int n, char *ps)
{
    int i;
    const static int size = LIMIT;

    for (i = size - 1; i >= 0; i--, n >>= 1)
        ps[i] = (01 & n) + '0';
    ps[size] = '\0';

    return ps;
}

void show_bstr(const char *str)
{
    int i = 0;

    while (str[i])
    {
        putchar(str[i]);
        if (++i % 4 == 0 && str[i])
            putchar(' ');
    }
}