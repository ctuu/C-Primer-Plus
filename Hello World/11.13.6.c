#include <stdio.h>
#define MAX 80
int is_within(char c, char *word);
int main(void)
{
    char word[MAX];
    char ch;
    fgets(word, MAX, stdin);

    while ((ch = getchar()) != EOF)
    {
        printf("%d\n", is_within(ch, word));
                while (getchar() != '\n')
            continue;
    }
    return 0;
}

int is_within(char c, char *word)
{
    while (*word != '\0')
    {
        if (*word == c)
            return 1;
        word++;
    }
    return 0;
}