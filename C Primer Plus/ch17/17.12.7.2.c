#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "17.12.7.h"

char menu(void);
void wordget(Tree * pt, char ch);
void showch(Tree *pt);
void sear(Tree *pt, char temp);

int main(void)
{
    char ch;
    char choice;
    char filename[40];
    Tree words;
    FILE *fp;
    scanf("%s", filename);
    if ((fp = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Can't open\"%s\" file.\n", filename);
        exit(EXIT_FAILURE);
    }

    InitializeTree(&words);
    while ((choice = menu()) != 'q')
    {
        switch (choice)
        {
        case 'l':
            showch(&words);
            break;
        case 'f':
            puts("Please enter a letter:");
            ch = getchar()) != EOF;
            while (getchar() != '\n')
                continue;
            sear(&words, ch);
            break;
        }
    }
    while ((ch = getc(fp)) != EOF)
        putc(ch, stdout);
    DeleteAll(words);
    fclose(fp);

    return 0;
}

char menu(void)
{
    int ch;

    puts("l) List all the words along with the number of occurrences");
    puts("f) Find a word occurre times");
    puts("q) quit");
    while ((ch = getchar()) != EOF)
    {
        while (getchar() != '\n')
            continue;
        ch = tolower(ch);
        if (strchr("lfq", ch) == NULL)
            puts("Please enter an l, f or q");
        else
            break;
    }
    if (ch == EOF)
        ch = 'q';

    return ch;
}