#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXSEAT 12
#define LIMIT 10

struct air
{
    int no;
    _Bool isbook;
    char last[LIMIT];
    char first[LIMIT];
};
char menu(void);
void show(void);
void add(void);
void del(void);

void eatline(void);
char *s_gets(char *st, int n);

int main(void)
{
    char choice;
    struct air titan[MAXSEAT];
    FILE *plist;

    if ((plist = fopen("list.dat", "a+b")) == NULL)
    {
        fputs("Can't open list.dat file.\n", stderr);
        exit(1);
    }

    while ((choice = menu()) != 'f')
        switch (choice)
        {
        case 'a':
            break;
        case 'b':
            break;
        case 'c':
            break;
        case 'd':
            break;
        case 'e':
            break;
        }
    puts("Bye.");
    return 0;
}

char menu(void)
{
    char ans;
    puts("To Choose a function, enter its letter label:");
    printf("a)  Show number of empty seats\n"
           "b)  Show list of empty seats\n"
           "c)  Show alphabetical list of seat\n");
    printf("d)  Assign a customer to a seat assignment\n"
           "e)  Delete a seat assignment\n"
           "f)  quit\n");
    ans = getchar();
    ans = tolower(ans);
    eatline();
    while (strchr("abcdef", ans) == NULL)
    {
        puts("Please enter a, ,b, c, d, e or f");
        ans = tolower(getchar());
        eatline();
    }
    return ans;
}

void eatline(void)
{
    while (getchar() != '\n')
        continue;
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