#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LIMIT 100
void ToUpper(char *);
void ToLower(char *);
int main(int argc, char *argv[])
{
    char ch[LIMIT];
    char temp;
    int a;
    for (a = 0; (temp = getchar()) != EOF; a++)
        ch[a] = temp;
    if (argc == 2)
    {
    if (strcmp(argv[1], "-u") == 0)
        ToUpper(ch);
    else if (strcmp(argv[1], "-l") == 0)
        ToLower(ch);
    }
    printf("\n");
    puts(ch);

    return 0;
}

void ToUpper(char *str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}
void ToLower(char *str)
{
    while (*str)
    {
        *str = tolower(*str);
        str++;
    }
}