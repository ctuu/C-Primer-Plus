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
void show(int tag, struct air titan[]);
void add(FILE *plist, struct air titan[]);
void del(FILE *plist, struct air titan[]);

void eatline(void);
char *s_gets(char *st, int n);

int size = sizeof(struct air);

int main(void)
{
    char choice;
    struct air titan[MAXSEAT];
    FILE *plist;

    if ((plist = fopen("list.dat", "r+b")) == NULL)
    {
        fputs("Can't open list.dat file.\n", stderr);
        exit(1);
    }

    rewind(plist);
    fread(&titan[0], size, MAXSEAT, plist);

    while ((choice = menu()) != 'f')
        switch (choice)
        {
        case 'a':
            show(0, titan);
            break;
        case 'b':
            show(1, titan);
            break;
        case 'c':
            show(2, titan);
            break;
        case 'd':
            add(plist, titan);
            break;
        case 'e':
            del(plist, titan);
            break;
        }
    fclose(plist);
    puts("Bye.");
    return 0;
}

char menu(void)
{
    char ans;
    puts("\nTo Choose a function, enter its letter label:");
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

void show(int tag, struct air titan[])
{
    int ct, sum;
    struct air *nu[12];
    struct air *temp;

    switch (tag)
    {
    case 0:
        for (sum = 0, ct = 0; ct < MAXSEAT; ct++)
            if (titan[ct].isbook == 0)
                sum++;
        printf("Empty seat: %d\n", sum);
        return;
    case 1:
        printf("\nNo.         Name         isBook\n");
        for (ct = 0; ct < MAXSEAT; ct++)
            if (titan[ct].isbook == 0)
            {
                printf("%2d       ---- ----          %d\n", ct, titan[ct].isbook);
            }
        return;
    case 2:
        printf("\nNo.         Name         isBook\n");

        for (ct = 0; ct < 12; ct++)
            nu[ct] = &titan[ct];
        for (ct = 0; ct < 12; ct++)
            for (sum = ct + 1; sum < 12; sum++)
            {
                if (titan[sum].isbook == 0 || titan[ct].isbook == 0)
                    continue;
                if (strcmp(nu[ct]->first, nu[sum]->first) > 0)
                {
                    temp = nu[ct];
                    nu[ct] = nu[sum];
                    nu[sum] = temp;
                }
            }
        for (ct = 0; ct < 12; ct++)
        {
            if (nu[ct]->isbook == 0)
                continue;
            printf("%2d %10s %-10s    %d\n", nu[ct]->no, nu[ct]->first, nu[ct]->last, titan[ct].isbook);
        }

        return;
    }
}

void add(FILE *plist, struct air titan[])
{
    int nu;
    int count = 0;
    for (nu = 0; nu < MAXSEAT; nu++)
        if (titan[nu].isbook == 1)
            count += 1;
    if (count == 12)
    {
        printf("Seats are full.\n");
        return;
    }

    printf("You can add a customer to No.:");
    for (nu = 0; nu < MAXSEAT; nu++)
        if (titan[nu].isbook == 0)
            printf("%d ", nu);
    printf("\nPlease enter a identification number: ");
    scanf("%d", &nu);
    eatline();
    printf("Enter first name: ");
    s_gets(titan[nu].first, LIMIT);
    printf("Enter last name: ");
    s_gets(titan[nu].last, LIMIT);
    titan[nu].isbook = 1;
    printf("Your Modify have changed.\n");

    rewind(plist);
    fwrite(&titan[0], size, MAXSEAT, plist);
}

void del(FILE *plist, struct air titan[])
{
    int cho;
    show(2, titan);
    printf("\nEnter the identification number you want to delete: ");
    scanf("%d",&cho);
    eatline();
    titan[cho].isbook = 0;
    printf("Your Modify have changed.\n");
    rewind(plist);
    fwrite(&titan[0], size, MAXSEAT, plist);
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