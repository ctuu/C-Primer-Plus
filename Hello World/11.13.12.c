#include <stdio.h>
#include <ctype.h>
#define MAX 80
int n_word(char *ch);
int n_capl(char *ch);
int n_lowl(char *ch);
int n_punc(char *ch);
int n_numb(char *ch);
int main(void)
{
    char ch[MAX];
    int i = 0;
    while ((ch[i] = getchar()) != EOF)
        i++;
    printf("\nnumber of words: %d\n", n_word(ch));
    printf("\nnumber of capital letters: %d\n", n_capl(ch));
    printf("\nnumber of lowercase letters: %d\n", n_lowl(ch));
    printf("\nnumber of punctuations: %d\n", n_punc(ch));
    printf("\nnumber of numbers: %d\n", n_numb(ch));
    return 0;
}

int n_word(char *ch)
{
    int co = 0;
    _Bool word = 0;
    if (*ch == ' ' || *ch == '\n')
        word == 1;
    while (*ch != '\0')
    {
        if ((*ch == ' ' || *ch == '\n') && word == 1)
            word = 0;
        else if (*ch != ' ' && *ch != '\n' && word == 0)
        {
            word = 1;
            co++;
        }
        ch++;
    }
    return co;
}

int n_capl(char *ch)
{
    int co = 0;
    while (*ch != '\0')
    {
        if (isupper(*ch))
            co++;
        ch++;
    }
    return co;
}

int n_lowl(char *ch)
{
    int co = 0;
    while (*ch != '\0')
    {
        if (islower(*ch))
            co++;
        ch++;
    }
    return co;
}

int n_punc(char *ch)
{
    int co = 0;
    while (*ch != '\0')
    {
        if (ispunct(*ch))
            co++;
        ch++;
    }
    return co;
}

int n_numb(char *ch)
{
    int co = 0;
    while (*ch != '\0')
    {
        if (isdigit(*ch))
            co++;
        ch++;
    }
    return co;
}