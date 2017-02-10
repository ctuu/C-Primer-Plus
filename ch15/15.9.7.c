#include <stdio.h>
#include <limits.h>

char *itobs(int, char *);
void show_bstr(const char *);

char menu(void);
void setting(char ch, unsigned int *font);
void showin(unsigned int font);
int main(void)
{
    char ch;
    unsigned int font = 0;
    showin(font);

    while ((ch = menu()) != 'q')
    {
        setting(ch, &font);
        showin(font);
    }
    puts("Bye!");
    return 0;
}

char menu(void)
{
    char ch;
    puts("f)change font    s)change size    a)change alignment");
    puts("b)toggle bold    i)toggle italic  u)toggle underline");
    puts("q)quit");
    scanf("%s", &ch);
    while (getchar() != '\n')
        continue;
    return ch;
}

void showin(unsigned int font)
{
    char bin_str[CHAR_BIT * sizeof(int) + 1];

    unsigned int temp;
    printf("\n\n\n    ID SIZE ALIGNMENT    B   I   U\n   ");
    temp = font >> 24;
    printf("%3d ", temp);
    temp = font >> 17;
    temp &= 0x7F;
    printf("%3d    ", temp);
    temp = font >> 15;
    temp &= 0x3;
    if (temp == 0)
        printf("left      ");
    else
        printf("%s", (temp == 1) ? "center    " : "right     ");
    temp = font >> 14;
    temp &= 1;
    printf("%s ", (temp) ? "on " : "off");
    temp = font >> 13;
    temp &= 1;
    printf("%s ", (temp) ? "on " : "off");
    temp = font >> 12;
    temp &= 1;
    printf("%s", (temp) ? "on " : "off");
    printf("\n\n");
    itobs(font, bin_str);
    show_bstr(bin_str);
    printf("\n\n");
}

void setting(char ch, unsigned int *font)
{

    char chr;
    unsigned int temp = 0;
    switch (ch)
    {
    case 'f':
        *font &= 0xFFFFFF;
        printf("Enter font ID (0-255): ");
        scanf("%d", &temp);
        temp <<= 24;
        *font |= temp;
        break;
    case 's':
        *font &= 0xFF01FFFF;
        printf("Enter font size (0-127): ");
        scanf("%d", &temp);
        temp <<= 17;
        *font |= temp;
        break;
    case 'a':
        *font &= 0xFFFE7FFF;
        puts("Select alignment:");
        puts("l)left    c)center    r)right");
        scanf("%s", &chr);
        while (getchar() != '\n')
            continue;
        if (chr == 'c')
            temp |= 1;
        else if (chr == 'r')
            temp |= 2;
        temp <<= 15;
        *font |= temp;
        break;
    case 'b':
        *font ^= 0x4000;
        break;
    case 'i':
        *font ^= 0x2000;
        break;
    case 'u':
        *font ^= 0x1000;
        break;
    }
}

char *itobs(int n, char *ps)
{
    int i;
    const static int size = CHAR_BIT * sizeof(int);

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
        if (++i == 4 || i == 8 || i == 12 || i == 15 || i == 17 || i == 18 || i == 19 || i == 20)
            putchar(' ');
        if (i == 8 ||  i == 15 || i == 17 || i == 18 || i == 19 || i == 20)
            putchar(' ');
    }
}
