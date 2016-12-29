#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "17.12.7.h"

char menu(void);
void wordget(Tree *pt, char cha);
void showch(Tree *pt);
void printitem(Item item);
void sear(Tree *pt, char in);

int main(void)
{
    char ch;
    char choice;
    char filename[40];
    Tree words;
    FILE *fp;
    InitializeTree(&words);
    printf("Please enter the file name:\n");
    scanf("%s", filename);
    if ((fp = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Can't open\"%s\" file.\n", filename);
        exit(EXIT_FAILURE);
    }
    printf("File read complete.\n");
    while (getchar() != '\n')
        continue;
    
    /*    if ((fp = fopen("17.12.7.2", "r")) == NULL)
    {
        fprintf(stderr, "Can't open\"17.12.7.2\" file.\n");
        exit(EXIT_FAILURE);
    }*/

    while ((ch = getc(fp)) != EOF)
    {
        wordget(&words, ch);
    }
    while ((choice = menu()) != 'q')
    {
        switch (choice)
        {
        case 'l':
            showch(&words);
            break;
        case 'f':
            puts("Please enter a letter:");
            ch = getchar();
            while (getchar() != '\n')
                continue;
            sear(&words, ch);
            break;
        }
    }
    DeleteAll(&words);
    fclose(fp);

    return 0;
}

char menu(void)
{
    int ch;

    puts("l) Show word list");
    puts("f) Find a word");
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

void wordget(Tree *pt, char cha)
{
    Item temp;
    temp.ch = cha;
    temp.ct = 1;
    AddItem(&temp, pt);
}

void showch(Tree *pt)
{
    if (TreeIsEmpty(pt))
        puts("No entries!");
    else
        Traverse(pt, printitem);
}

void printitem(Item item)
{
    printf("\"%c\":%2d\n", item.ch, item.ct);
}

void sear(Tree *pt, char in)
{
    Item temp;
    Trnode *loc;
    temp.ch = in;
    temp.ct = 0;
    loc = InTree(&temp, pt);
    if (loc == NULL)
        printf("\"%c\" is not in file.\n", in);
    else
        printf("\"%c\":%2d\n", in, (loc->item).ct);
}