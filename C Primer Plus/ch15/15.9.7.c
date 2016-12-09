#include <stdio.h>

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
    unsigned int temp;
    printf("\n\n\n    ID SIZE ALIGNMENT    B   I   U\n   ");
    temp = font >> 13;
    printf("%3d ", temp);
    // temp = font <<= 8;
    // temp >>= 4;
    printf("%3d\n\n", temp);
}

void setting(char ch, unsigned int *font)
{
    unsigned int temp;
    switch (ch)
    {
    case 'f':
        printf("Enter font ID (0-255): ");
        scanf("%d", &temp);
        temp <<= 13;
        *font |= temp;
        break;
    case 's':
        printf("Enter font size (0-127): ");
        scanf("%d", &temp);
        temp <<= 7;
        *font |= temp;
        break;
    case 'a':
        break;
    case 'b':
        break;
    case 'i':
        break;
    case 'u':
        break;
    }
}