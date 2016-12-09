#include <stdio.h>
#define LEFT 0
#define RIGHT 1
#define CENTER 2

struct font
{
    unsigned int fid : 8;
    unsigned int size : 7;
    unsigned int align : 2;
    _Bool bold;
    _Bool italic;
    _Bool unline;
};

char menu(void);
void showin(const struct font one);
void setting(char ch, struct font *one);
int main(void)
{
    char ch;
    struct font one = {0, 0, 0, 0, 0, 0};
    showin(one);
    while ((ch = menu()) != 'q')
    {
        setting(ch, &one);
        showin(one);
    }
    puts("Bye!");
    return 0;
}

void showin(const struct font one)
{
    printf("\n\n\n    ID SIZE ALIGNMENT    B   I   U\n   ");
    printf("%3d  %3d   ", one.fid, one.size);
    if (one.align == 0)
        printf("left      ");
    else
        printf("%s", (one.align == 1) ? "center    " : "right     ");
    printf("%s %s %s\n\n", (one.bold) ? "on " : "off", (one.italic) ? "on " : "off", (one.unline) ? "on " : "off");
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

void setting(char ch, struct font *one)
{
    int i;
    char chr;
    switch (ch)
    {
    case 'f':
        printf("Enter font ID (0-255): ");
        scanf("%d", &i);
        one->fid &= 0;
        one->fid |= i;
        break;
    case 's':
        printf("Enter font size (0-127): ");
        scanf("%d", &i);
        one->size &= 0;
        one->size |= i;
        break;
    case 'a':
        puts("Select alignment:");
        puts("l)left    c)center    r)right");
        scanf("%s", &chr);
        while (getchar() != '\n')
            continue;
        one->align &= 0;
        if (chr == 'c')
            one->align |= 1;
        else if (chr == 'r')
            one->align |= 2;
        break;
    case 'b':
        one->bold = ~(one->bold);
        break;
    case 'i':
        one->italic = ~(one->italic);
        break;
    case 'u':
        one->unline = ~(one->unline);
        break;
    }
}