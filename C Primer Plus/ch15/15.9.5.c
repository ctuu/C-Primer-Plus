#include <stdio.h>
#define LIMIT 8

int btois(char *pbin, int bit);
char *itobs(int n, char *ps);
void show_bstr(const char *str);
void rotate_1(int num, int ct);

int main(void)
{
    char temp[LIMIT + 1];
    unsigned int num, ct;
    scanf("%d%d", &num, &ct);
    show_bstr(itobs(num, temp));
    printf("\n\n");
    rotate_1(num, ct);
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

void rotate_1(int num, int ct)
{
    char temp[LIMIT + 1];
    char te;
    int i;
    itobs(num, temp);
    for (; ct > 0; ct--)
    {
        te = temp[0];
        for (i = 0; i < LIMIT - 1; i++)
            temp[i] = temp[i + 1];
        temp[i] = te;
    }
    printf("%d\n",btois(temp, LIMIT));
    show_bstr(temp);
}