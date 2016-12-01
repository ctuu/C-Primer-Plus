#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10
char *s_gets(char *st, int n);
struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
    //int exist;
};
void eatline(void);
char menu(void);
void add(FILE *pbooks, struct book library[], int count, int filecount);
void show(struct book library[], int count);
int main(void)
{
    int count = 0;
    int index, filecount;
    char choice;
    struct book library[MAXBKS];
    FILE *pbooks;
    int size = sizeof(struct book);

    if ((pbooks = fopen("book.dat", "a+b")) == NULL)
    {
        fputs("Can't open book.dat file\n", stderr);
        exit(1);
    }

    rewind(pbooks);
    while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
        count++;
    printf("You have %d books now.\n", count);
    filecount = count;

    while ((choice = menu()) != 'q')
        switch (choice)
        {
        case 's':
            show(library, count);
            break;
        case 'a':
            add(pbooks, library, count, filecount);
            break;
        case 'd':
            break;
        case 'r':

            break;
        }

    puts("Bye.\n");
    fclose(pbooks);

    return 0;
}

char menu(void)
{
    char ans;
    printf("\ns) Show your Books      a) Add books\nd) Delete book          r) revison book\n");
    printf("q) Quit\n");
    ans = getchar();
    ans = tolower(ans);
    eatline();
    while (strchr("sadrq", ans) == NULL)
    {
        puts("Please enter a s, a, d, r or q:");
        ans = tolower(getchar());
        eatline();
    }
    return ans;
}

void show(struct book library[], int count)
{
    int index;
    int size = sizeof(struct book);
    if (count > 0)
    {
        puts("Here is the list of your books:");
        for (index = 0; index < count ; index++)
            printf("(%d) %s by %s: $%.2f\n", index, library[index].title,
                   library[index].author, library[index].value);
    }
    else
        puts("No books? Too bad.\n");
}

void add(FILE *pbooks, struct book library[], int count, int filecount)
{
    int size = sizeof(struct book);
    printf("%d\n", size);
    if (count == MAXBKS)
    {
        fputs("The book.dat file is full.", stderr);
        exit(2);
    }
    else
    {
        puts("Please add new book titles.");
        puts("Please [enter] at the start of a line to stop.");
        while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
        {
            puts("Now enter the author.");
            s_gets(library[count].author, MAXAUTL);
            puts("Now enter the value.");
            scanf("%f", &library[count].value);
            while (getchar() != '\n')
                continue;
         //   library[count].exist = 1;
            count++;
            if (count < MAXBKS)
                puts("Enter the next title.");
        }
        fwrite(&library[filecount], size, count - filecount,
               pbooks);
        printf("Your Modify have changed.\n");
        show(library, count);
    }
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}
void eatline(void)
{
    while (getchar() != '\n')
        continue;
}