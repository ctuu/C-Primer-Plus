#include <stdio.h>
char *search(char *word, char ch);
int main(void)
{
    char word[80];
    char ch;
    int c;
    while (fgets(word, 80, stdin) != NULL)
    {
        ch = getchar();
        while (getchar() != '\n')
            continue;
        printf("\n%p\n", search(word, ch));
    }
    return 0;
}

char *search(char *word, char ch)
{
    while (*word != '\0')
    {
        if (*word == ch)
            return word;
        word++;
    }
    return 0;
}