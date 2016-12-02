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
    _Bool exist;
};
void eatline(void);
char menu(void);
char upmenu(void);
int add(FILE *pbooks, struct book library[], int count, int filecount, int size);
void show(struct book library[], int count);
int del(FILE *pbooks, struct book library[], int count, int filecount, int size);
void rev(FILE *pbooks, struct book library[], int count, int filecount, int size);
int main(void)
{
    int count = 0;
    int index, filecount;
    char choice;
    struct book library[MAXBKS];
    FILE *pbooks;
    int size = sizeof(struct book);

    if ((pbooks = fopen("book.dat", "r+b")) == NULL)
    {
        fputs("Can't open book.dat file\n", stderr);
        exit(1);
    }

    rewind(pbooks);
    while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1 && library[count].exist == 1)
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
            count = add(pbooks, library, count, filecount, size);
            filecount = count;
            break;
        case 'd':
            count = del(pbooks, library, count, filecount, size);
            filecount = count;
            break;
        case 'r':
            rev(pbooks, library, count, filecount, size);
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
        puts("Please enter a s, a, d, r or q: ");
        ans = tolower(getchar());
        eatline();
    }
    return ans;
}

void show(struct book library[], int count)
{
    int index;
    if (count > 0)
    {
        puts("\nHere is the list of your books:");
        for (index = 0; index < count && library[index].exist == 1; index++)
            printf("(%d) %s by %s: $%.2f\n", index, library[index].title,
                   library[index].author, library[index].value);
    }
    else
        puts("No books? Too bad.\n");
}

int add(FILE *pbooks, struct book library[], int count, int filecount, int size)
{
    if (count == MAXBKS)
    {
        fputs("The book.dat file is full.", stderr);
        return count;
    }
    else
    {
        printf("count = %d\n",count);
        puts("Please add new book titles.");
        puts("Please [enter] at the start of a line to stop.");
        while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
        {
            puts("Now enter the author.");
            s_gets(library[count].author, MAXAUTL);
            puts("Now enter the value.");
            scanf("%f", &library[count].value);
            eatline();
            library[count].exist = 1;
            count++;
            if (count < MAXBKS)
                puts("Enter the next title.");
        }
        printf("Your Modify have changed.\n");
        rewind(pbooks);
        fwrite(&library[0], size, count, pbooks);
        return count;
    }
}

int del(FILE *pbooks, struct book library[], int count, int filecount, int size)
{
    int choose;
    if (count == 0)
    {
        fputs("The book.dat file is empty.", stderr);
        return count;
    }
    else
    {
        show(library, count);
        printf("please choose the number you want to delete(0 to %d):\n", --count);
        scanf("%d", &choose);
        eatline();
        library[choose].title[0] = '\0';
        library[choose].author[0] = '\0';
        library[choose].value = 0;
        library[choose].exist = 0;
        if (choose < count)
        {
            for (; choose < count; choose++)
            {
                strcpy(library[choose].title, library[choose + 1].title);
                strcpy(library[choose].author, library[choose + 1].author);
                library[choose].value = library[choose + 1].value;
                library[choose].exist = library[choose + 1].exist;
            }
            library[count].exist = 0;
        }
    }
    rewind(pbooks);
    fwrite(&library[0], size, count + 1, pbooks);
    printf("Your Modify have changed.\n");
    return count;
}

void rev(FILE *pbooks, struct book library[], int count, int filecount, int size)
{
    int choose;
    char ans;
    if (count == 0)
    {
        fputs("The book.dat file is empty.", stderr);
        return;
    }
    else
    {
        show(library, count);
        printf("please choose the number you want to update(0 to %d):\n", count - 1);
        scanf("%d", &choose);
        eatline();
        while ((ans = upmenu()) != 'q')
            switch (ans)
            {
            case 't':
                puts("Please enter a new title.");
                s_gets(library[choose].title, MAXTITL);
                eatline();
                break;
            case 'a':
                puts("Please enter a new author.");
                s_gets(library[choose].author, MAXAUTL);
                eatline();
                break;
            case 'v':
                puts("Please enter a value.");
                scanf("%f", &library[choose].value);
                eatline();
                break;
            }
        rewind(pbooks);
        fwrite(&library[0], size, count, pbooks);
        printf("Your Modify have changed.\n");
    }
}

char upmenu(void)
{
    char ans;
    printf("Please choose the type you want to update:\nt) title      a) author\nv) value      q) quit\n");
    ans = getchar();
    ans = tolower(ans);
    eatline();
    while (strchr("tavq", ans) == NULL)
    {
        puts("Please enter a t, a, v or q: ");
        ans = tolower(getchar());
        eatline();
    }
    return ans;
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