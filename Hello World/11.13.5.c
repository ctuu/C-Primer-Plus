#include <stdio.h>
char search(char *word, char *ch);
char *s_gets(char *st, int n);
int main(void)
{
    char word[80];
    char ch[1];
    int c;
    while (s_gets(word, 80) != NULL && s_gets(ch, 1) != NULL)
    {
      //  printf("\n\n%c",search(word, ch));
        
    }
    return 0;
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

char search(char * word, char * ch)
{
    for (; word != '\0'; word++)
    {
        if (*word == *ch)
             {
            printf("%s", *word);
                 return *word;
             }
    }
    return 0;
}